#include <iostream>
#include <cassert>

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
    Stack(int cap): capacity(cap <= 0 ? 1 : cap), size(0), data(new int[capacity]) {}

    ~Stack()
    {
        delete[] data;
    }

    void push(int value)
    {
    }

    void pop()
    {
    }

    int top() const
    {
    }

    bool isEmpty() const
    {
    }

    int getSize() const
    {
    }

    void print() const
    {
    }
};

void testStack(Stack &stack)
{
    assert(stack.isEmpty());

    stack.push(10);
    stack.push(20);
    stack.push(30);

    assert(stack.getSize() == 3);
    assert(stack.top() == 30);

    stack.pop();
    assert(stack.top() == 20);

    stack.pop();
    stack.pop();
    assert(stack.isEmpty());
}

int main()
{
    Stack myStack(10);
    testStack(myStack);
    std::cout << "All tests passed!\n";
    return 0;
}
