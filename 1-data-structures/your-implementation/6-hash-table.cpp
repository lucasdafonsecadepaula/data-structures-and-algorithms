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
    }

    void rehash()
    {
    }

    void delRec(Node *node)
    {
    }

public:
    HashTable(int cap = 10)
    {
    }
    ~HashTable()
    {
    }

    void insert(const string &key, int value)
    {
    }

    bool search(const string &key, int &value) const
    {
    }

    void remove(const string &key)
    {
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
