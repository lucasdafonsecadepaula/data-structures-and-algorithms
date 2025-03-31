#include <iostream>
#include <string>
#include <cassert>
using namespace std;

class File
{
public:
    string name;
    File(string name) : name(name) {}
};

// LRU (Least Recently Used) Cache: Removes the least recently accessed item when full.
class LRUCache
{
private:
    File **cache;
    int capacity;
    int size;

    int getIndexByKey(const string &key)
    {
    }

    void moveToFront(int index)
    {
    }

public:
    LRUCache(int cap = 10) : capacity(cap), size(0), cache(new File *[cap]()) {}

    ~LRUCache()
    {
        for (int i = 0; i < size; i++)
            delete cache[i];
        delete[] cache;
    }

    int get(const string &key)
    {
    }

    void put(const string &key)
    {
    }

    bool contains(const string &key)
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

int main()
{
    LRUCache cache(3);
    cache.put("File1.txt");
    cache.put("File2.doc");
    cache.put("File3.pdf");
    assert(cache.contains("File1.txt"));
    assert(cache.contains("File2.doc"));
    assert(cache.contains("File3.pdf"));
    assert(!cache.contains("File4.jpg"));
    cache.get("File1.txt");
    cache.get("File2.doc");
    cache.put("File4.jpg");
    assert(cache.contains("File4.jpg"));
    assert(!cache.contains("File3.pdf"));
    cache.get("File4.jpg");
    cache.put("File5.png");
    assert(cache.contains("File5.png"));
    assert(!cache.contains("File1.txt"));
    cout << "All tests passed!\n";
    return 0;
}
