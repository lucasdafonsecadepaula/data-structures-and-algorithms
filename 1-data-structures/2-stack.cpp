#include <iostream>
#include <cassert>
using namespace std;

class Stack
{
private:
    int *data;
    int size;
    int capacity;

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
    Stack(int cap) : capacity(cap <= 0 ? 1 : cap), size(0), data(new int[capacity]) {}

    ~Stack()
    {
        delete[] data;
    }

    void push(int value)
    {
        if (size >= capacity)
        {
            resize();
        }
        data[size++] = value;
    }

    void pop()
    {
        if (size > 0)
        {
            size--;
        }
    }

    int top() const
    {
        if (isEmpty())
        {
            throw out_of_range("Stack is empty!");
        }
        return data[size - 1];
    }

    bool isEmpty() const
    {
        return size == 0;
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

void testStack()
{
    Stack stack(2);

    assert(stack.isEmpty());
    assert(stack.getSize() == 0);

    stack.push(5);
    assert(stack.top() == 5);
    assert(stack.getSize() == 1);
    assert(!stack.isEmpty());

    stack.push(10);
    assert(stack.top() == 10);
    assert(stack.getSize() == 2);

    stack.push(15);
    assert(stack.getSize() == 3);
    assert(stack.top() == 15);

    stack.pop();
    assert(stack.top() == 10);
    assert(stack.getSize() == 2);

    stack.pop();
    assert(stack.top() == 5);
    assert(stack.getSize() == 1);

    stack.pop();
    assert(stack.isEmpty());
    assert(stack.getSize() == 0);

    stack.pop();
    assert(stack.isEmpty());
}

int main()
{
    testStack();
    cout << "All tests passed!\n";
    return 0;
}
