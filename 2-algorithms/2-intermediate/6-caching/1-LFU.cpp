#include <iostream>
#include <string>
#include <cassert>
using namespace std;

class File
{
public:
    string name;
    int freq;
    File(string name) : name(name), freq(0) {}
};

// LFU (Least Frequently Used) Cache: Removes the item with the lowest access frequency when full.
class LFUCache
{
private:
    File **cache;
    int capacity;
    int size;

    int getLowestFreq()
    {
        int lowestI = 0;
        int lowestFreq = cache[0]->freq;
        for (int i = 1; i < size; i++)
        {
            if (cache[i]->freq < lowestFreq)
            {
                lowestFreq = cache[i]->freq;
                lowestI = i;
            }
        }
        return lowestI;
    }

    int getIndexByKey(const string &key)
    {
        for (int i = 0; i < size; i++)
        {
            if (cache[i]->name == key)
                return i;
        }
        return -1;
    }

public:
    LFUCache(int cap = 10) : capacity(cap), size(0), cache(new File *[cap]()) {}

    ~LFUCache()
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
        cache[index]->freq++;
        return 1;
    }

    void put(const string &key)
    {
        int index = getIndexByKey(key);
        if (index >= 0)
        {
            cache[index]->freq++;
            return;
        }

        File *newFile = new File(key);
        newFile->freq++;

        if (size >= capacity)
        {
            int replaceIndex = getLowestFreq();
            delete cache[replaceIndex];
            cache[replaceIndex] = newFile;
        }
        else
        {
            cache[size++] = newFile;
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
    LFUCache cache(3);
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
    cache.get("File4.jpg");
    cache.put("File5.png");
    assert(cache.contains("File5.png"));
    assert(!cache.contains("File1.txt"));
    cout << "All tests passed!\n";
    return 0;
}
