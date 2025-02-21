#include <iostream>
#include <cassert>
#include <string>
using namespace std;

class Node
{
public:
    string key;
    int value;
    Node *next;

    Node(string key, int value) : key(key), value(value), next(nullptr) {}
};

class HashTable
{
private:
    Node **table;
    int capacity;
    int size;
    const float loadFactorThreshold = 0.7;

    int hashFunction(const string &key) const
    {
        unsigned long hash = 5381;
        for (char c : key)
        {
            hash = ((hash << 5) + hash) + c;
        }
        return hash % capacity;
    }

    void rehash()
    {
        int oldCapacity = capacity;
        Node **oldTable = table;

        capacity *= 2;
        table = new Node *[capacity];
        for (int i = 0; i < capacity; i++)
        {
            table[i] = nullptr;
        }

        for (int i = 0; i < oldCapacity; i++)
        {
            Node *current = oldTable[i];
            while (current != nullptr)
            {
                Node *next = current->next;
                int newIndex = hashFunction(current->key);
                current->next = table[newIndex];
                table[newIndex] = current;
                current = next;
            }
        }

        delete[] oldTable;
    }

    void delRec(Node *node)
    {
        if (node == nullptr)
            return;
        delRec(node->next);
        delete node;
    }

public:
    HashTable(int cap = 10) : capacity(cap), size(0), table(new Node *[cap])
    {
        for (int i = 0; i < capacity; i++)
        {
            table[i] = nullptr;
        }
    }
    ~HashTable()
    {
        for (int i = 0; i < capacity; i++)
        {
            if (table[i] != nullptr)
            {
                delRec(table[i]);
            }
        }
        delete[] table;
    }

    void insert(const string &key, int value)
    {
        if ((float)size / capacity > loadFactorThreshold)
        {
            rehash();
        }

        int index = hashFunction(key);

        Node *cur = table[index];

        if (cur == nullptr)
        {
            table[index] = new Node(key, value);
            size++;
            return;
        }

        while (cur != nullptr)
        {
            if (cur->key == key)
            {
                cur->value = value;
                return;
            }
            cur = cur->next;
        }

        Node *newNode = new Node(key, value);
        newNode->next = table[index];
        table[index] = newNode;
        size++;
    }

    bool search(const string &key, int &value) const
    {
        int index = hashFunction(key);
        Node *cur = table[index];
        while (cur != nullptr)
        {
            if (cur->key == key)
            {
                value = cur->value;
                return true;
            }
            cur = cur->next;
        }
        return false;
    }

    void remove(const string &key)
    {
        int index = hashFunction(key);
        Node *cur = table[index];

        if (cur == nullptr)
            return;

        if (cur->key == key)
        {
            table[index] = cur->next;
            delete cur;
            size--;
            return;
        }

        while (cur->next != nullptr && cur->next->key != key)
        {
            cur = cur->next;
        }

        if (cur->next == nullptr)
        {
            return;
        }

        Node *temp = cur->next;
        cur->next = temp->next;
        delete temp;
        size--;
    }
};

//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//

void testHashTable()
{
    HashTable hashTable;

    hashTable.insert("apple", 10);
    hashTable.insert("banana", 20);
    hashTable.insert("orange", 30);

    int value;
    assert(hashTable.search("apple", value) && value == 10);
    assert(hashTable.search("banana", value) && value == 20);
    assert(hashTable.search("orange", value) && value == 30);

    hashTable.insert("banana", 25);
    assert(hashTable.search("banana", value) && value == 25);

    hashTable.remove("banana");
    assert(!hashTable.search("banana", value));

    hashTable.remove("nonexistent");

    for (int i = 0; i < 20; i++)
    {
        hashTable.insert("key" + to_string(i), i * 5);
    }

    for (int i = 0; i < 20; i++)
    {
        assert(hashTable.search("key" + to_string(i), value) && value == i * 5);
    }

    hashTable.insert("collision1", 100);
    hashTable.insert("collision2", 200);
    hashTable.insert("collision3", 300);

    assert(hashTable.search("collision1", value) && value == 100);
    assert(hashTable.search("collision2", value) && value == 200);
    assert(hashTable.search("collision3", value) && value == 300);

    hashTable.remove("collision2");
    assert(!hashTable.search("collision2", value));
    assert(hashTable.search("collision1", value) && value == 100);
    assert(hashTable.search("collision3", value) && value == 300);

    cout << "All Hash Table tests passed!\n";
}
int main()
{
    testHashTable();
    return 0;
}
