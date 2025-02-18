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
    }

public:
    Array(int cap = 1) {}

    ~Array() {}

    void insert(int index, int value)
    {
    }

    void remove(int index)
    {
    }

    int get(int index) const
    {
    }

    int getSize() const
    {
    }

    void print() const
    {
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
