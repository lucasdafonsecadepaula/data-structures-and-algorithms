#include <iostream>
#include <cassert>

class Queue
{
private:
    int *data;
    int size;
    int capacity;
    int frontIndex;

    void resize()
    {
        capacity *= 2;
        int *temp = new int[capacity];

        for (int i = 0; i < size; i++)
        {
            temp[i] = data[frontIndex + i];
        }

        delete[] data;
        data = temp;
        frontIndex = 0;
    }

public:
    Queue(int cap) : capacity(cap <= 0 ? 1 : cap), size(0), frontIndex(0), data(new int[capacity]) {}

    ~Queue()
    {
        delete[] data;
    }

    void enqueue(int value)
    {
        if (frontIndex + size == capacity)
        {
            resize();
        }

        data[frontIndex + size] = value;
        size++;
    }

    void dequeue()
    {
        if (isEmpty())
        {
            std::cout << "Queue is empty! Cannot dequeue.\n";
            return;
        }

        frontIndex++;
        size--;

        if (size == 0)
        {
            frontIndex = 0;
        }
    }

    int front() const
    {
        assert(size > 0 && "Queue is empty!");
        return data[frontIndex];
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
        std::cout << "Printing Queue: ";
        for (int i = 0; i < size; i++)
        {
            std::cout << data[frontIndex + i] << ", ";
        }
        std::cout << std::endl;
    }
};

void testQueue(Queue &queue)
{
    assert(queue.isEmpty());

    queue.enqueue(10);
    queue.enqueue(20);
    queue.enqueue(30);

    assert(queue.getSize() == 3);
    assert(queue.front() == 10);

    queue.dequeue();
    assert(queue.front() == 20);

    queue.dequeue();
    queue.dequeue();
    assert(queue.isEmpty());
}

int main()
{
    Queue myQueue(3);
    testQueue(myQueue);
    std::cout << "All tests passed!\n";
    return 0;
}
