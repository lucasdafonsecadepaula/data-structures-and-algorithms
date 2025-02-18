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

        if (table[index] == nullptr)
        {
            table[index] = new Node(key, value);
            size++;
        }
        else
        {
            Node *cur = table[index];

            while (cur->next != nullptr && cur->next->key != key)
            {
                cur = cur->next;
            }

            if (cur->next == nullptr)
            {
                cur->next = new Node(key, value);
                size++;
            }
            else
            {
                cur->next->value = value;
            }
        }
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

    void print() const
    {
        cout << "Hash Table Contents:\n";
        for (int i = 0; i < capacity; i++)
        {
            cout << "Bucket " << i << ": ";
            Node *cur = table[i];
            while (cur != nullptr)
            {
                cout << "Key: " << cur->key << " Value: " << cur->value << " | ";
                cur = cur->next;
            }
            cout << "\n";
        }
    }
};

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

    hashTable.remove("banana");
    assert(!hashTable.search("banana", value));

    hashTable.insert("kiwi", 40);
    hashTable.insert("grape", 50);
    hashTable.insert("pear", 60);

    assert(hashTable.search("kiwi", value) && value == 40);
    assert(hashTable.search("grape", value) && value == 50);
    assert(hashTable.search("pear", value) && value == 60);

    cout << "All Hash Table tests passed!\n";
}

int main()
{
    testHashTable();
    return 0;
}
