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
