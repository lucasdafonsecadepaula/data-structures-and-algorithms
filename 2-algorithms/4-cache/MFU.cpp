#include <iostream>
#include <string>
#include <cassert>
using namespace std;

class File
{
public:
    string name;
    int frequency;
    File(string name) : name(name), frequency(1) {}
};

// MFU (Most Frequently Used) Cache: Removes the item with the highest access frequency when full.
class MFUCache
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

    int getMostFrequentIndex()
    {
        int maxFreqIndex = 0;
        for (int i = 1; i < size; i++)
        {
            if (cache[i]->frequency > cache[maxFreqIndex]->frequency)
                maxFreqIndex = i;
        }
        return maxFreqIndex;
    }

public:
    MFUCache(int cap = 10) : capacity(cap), size(0), cache(new File *[cap]()) {}

    ~MFUCache()
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
            cout << "[MISS] File '" << key << "' not found in cache.\n";
            return -1;
        }

        cache[index]->frequency++;
        cout << "[HIT] File '" << key << "' accessed. Frequency: " << cache[index]->frequency << "\n";
        return 1;
    }

    void put(const string &key)
    {
        int index = getIndexByKey(key);
        if (index != -1)
        {
            cache[index]->frequency++;
            return;
        }

        File *newFile = new File(key);
        if (size >= capacity)
        {
            int removeIndex = getMostFrequentIndex();
            delete cache[removeIndex];

            for (int i = removeIndex; i < size - 1; i++)
            {
                cache[i] = cache[i + 1];
            }
            cache[size - 1] = newFile;
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
    MFUCache cache(3);
    cache.put("File1.txt");
    cache.put("File2.doc");
    cache.put("File3.pdf");
    assert(cache.contains("File1.txt"));
    assert(cache.contains("File2.doc"));
    assert(cache.contains("File3.pdf"));
    assert(!cache.contains("File4.jpg"));
    cache.get("File1.txt");
    cache.get("File1.txt");
    cache.get("File2.doc");
    cache.put("File4.jpg");
    assert(cache.contains("File4.jpg"));
    assert(!cache.contains("File1.txt"));
    cache.get("File2.doc");
    cache.get("File2.doc");
    cache.put("File5.png");
    assert(cache.contains("File5.png"));
    assert(!cache.contains("File2.doc"));
    cout << "All tests passed!\n";
    return 0;
}
