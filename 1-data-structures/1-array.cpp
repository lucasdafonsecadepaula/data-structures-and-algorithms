#include <iostream>
#include <cassert>
using namespace std;

class Array
{
private:
    int *data;
    int capacity;
    int size;

    void resize()
    {
        capacity *= 2;
        int *temp = new int[capacity];

        for (int i = 0; i < size; i++)
        {
            temp[i] = data[i];
        }

        delete[] data;
        data = temp;
    }

public:
    Array(int cap) : capacity(cap <= 0 ? 1 : cap), size(0), data(new int[capacity]) {}

    ~Array()
    {
        delete[] data;
    }

    void insert(int index, int value)
    {
        if (index < 0 || index > size)
        {
            throw out_of_range("Index out of bounds");
            return;
        }

        if (size >= capacity)
        {
            resize();
        }

        for (int i = size; i > index; i--)
        {
            data[i] = data[i - 1];
        }

        data[index] = value;
        size++;
    }

    void remove(int index)
    {
        if (index < 0 || index >= size)
        {
            throw out_of_range("Index out of bounds");
            return;
        }

        for (int i = index; i < size - 1; i++)
        {
            data[i] = data[i + 1];
        }

        size--;

        data[size] = 0;
    }

    int get(int index) const
    {
        if (index < 0 || index >= size)
        {
            throw out_of_range("Index out of bounds");
        }
        return data[index];
    }

    int getSize() const
    {
        return size;
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

void testArray(Array &arr)
{
    arr.insert(0, 10);
    arr.insert(1, 20);
    arr.insert(2, 30);
    arr.insert(3, 40);
    arr.insert(4, 50);

    assert(arr.getSize() == 5);
    assert(arr.get(0) == 10);
    assert(arr.get(1) == 20);
    assert(arr.get(2) == 30);
    assert(arr.get(3) == 40);
    assert(arr.get(4) == 50);

    arr.insert(0, 5);
    arr.insert(3, 25);
    arr.insert(arr.getSize(), 60);

    assert(arr.get(0) == 5);
    assert(arr.get(1) == 10);
    assert(arr.get(3) == 25);
    assert(arr.get(6) == 50);
    assert(arr.get(arr.getSize() - 1) == 60);
    assert(arr.getSize() == 8);

    arr.remove(0);
    assert(arr.get(0) == 10);
    assert(arr.getSize() == 7);

    arr.remove(3);
    assert(arr.get(3) == 40);
    assert(arr.getSize() == 6);

    arr.remove(arr.getSize() - 1);
    assert(arr.getSize() == 5);

    try
    {
        arr.insert(-1, 99);
        assert(false);
    }
    catch (const std::out_of_range &)
    {
    }

    try
    {
        arr.insert(100, 99);
        assert(false);
    }
    catch (const std::out_of_range &)
    {
    }

    assert(arr.getSize() == 5);

    try
    {
        arr.remove(-1);
        assert(false);
    }
    catch (const std::out_of_range &)
    {
    }

    try
    {
        arr.remove(100);
        assert(false);
    }
    catch (const std::out_of_range &)
    {
    }

    assert(arr.getSize() == 5);

    try
    {
        arr.get(-1);
        assert(false);
    }
    catch (const std::out_of_range &)
    {
    }

    try
    {
        arr.get(100);
        assert(false);
    }
    catch (const std::out_of_range &)
    {
    }
}

int main()
{
    try
    {
        Array myArray(2);
        testArray(myArray);
        cout << "All tests passed!\n";
    }
    catch (const exception &e)
    {
        cout << "Exception: " << e.what() << endl;
    }
    return 0;
}
