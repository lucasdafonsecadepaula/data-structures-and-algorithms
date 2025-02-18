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
        assert(size > 0 && "Stack is empty!");
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

    void print() const
    {
        std::cout << "Printing Stack: ";
        for (int i = 0; i < size; i++)
        {
            std::cout << data[i] << ", ";
        }
        std::cout << std::endl;
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
