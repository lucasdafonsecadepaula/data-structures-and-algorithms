#include <iostream>
#include <cassert>

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
            std::cout << "Out of bounds!\n";
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
            std::cout << "Out of bounds!\n";
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
            throw std::out_of_range("Index out of bounds");
        }
        return data[index];
    }

    int getSize() const
    {
        return size;
    }

    void print() const
    {
        std::cout << "Printing array: ";
        for (int i = 0; i < size; i++)
        {
            std::cout << data[i] << ", ";
        }
        std::cout << std::endl;
    }
};

void testArray(Array &arr)
{
    arr.insert(0, 10);
    arr.insert(1, 20);
    arr.insert(2, 30);

    assert(arr.get(0) == 10);
    assert(arr.get(1) == 20);
    assert(arr.get(2) == 30);

    arr.remove(1);
    assert(arr.get(1) == 30);
    assert(arr.getSize() == 2);
}

int main()
{
    try
    {
        Array myArray(2);
        testArray(myArray);
        std::cout << "All tests passed!\n";
    }
    catch (const std::exception &e)
    {
        std::cout << "Exception: " << e.what() << std::endl;
    }
    return 0;
}
