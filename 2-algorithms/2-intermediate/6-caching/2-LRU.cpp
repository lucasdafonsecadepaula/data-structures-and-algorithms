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
        for (int i = 0; i < size; i++)
        {
            if (cache[i]->name == key)
                return i;
        }
        return -1;
    }

    void moveToFront(int index)
    {
        File *temp = cache[index];
        for (int i = index; i > 0; i--)
        {
            cache[i] = cache[i - 1];
        }
        cache[0] = temp;
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
        int index = getIndexByKey(key);
        if (index < 0)
        {
            return -1;
        }

        moveToFront(index);

        return 1;
    }

    void put(const string &key)
    {
        int index = getIndexByKey(key);
        if (index != -1)
        {
            moveToFront(index);
            return;
        }

        File *newFile = new File(key);
        if (size >= capacity)
        {
            delete cache[capacity - 1];
            for (int i = capacity - 1; i > 0; i--)
            {
                cache[i] = cache[i - 1];
            }
            cache[0] = newFile;
        }
        else
        {
            for (int i = size; i > 0; i--)
            {
                cache[i] = cache[i - 1];
            }
            cache[0] = newFile;
            size++;
        }
    }

    bool contains(const string &key)
    {
        return getIndexByKey(key) >= 0;
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
