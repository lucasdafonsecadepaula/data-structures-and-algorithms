#include <iostream>
#include <cassert>
using namespace std;

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
            runtime_error("Queue is empty!");
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
        if (isEmpty())
        {
            runtime_error("Queue is empty!");
        }
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

void testQueue(Queue &queue)
{
    assert(queue.isEmpty());
    assert(queue.getSize() == 0);

    queue.enqueue(10);
    assert(!queue.isEmpty());
    assert(queue.getSize() == 1);
    assert(queue.front() == 10);

    queue.enqueue(20);
    queue.enqueue(30);
    assert(queue.getSize() == 3);
    assert(queue.front() == 10);

    queue.dequeue();
    assert(queue.getSize() == 2);
    assert(queue.front() == 20);

    queue.dequeue();
    assert(queue.getSize() == 1);
    assert(queue.front() == 30);

    queue.dequeue();
    assert(queue.isEmpty());
    assert(queue.getSize() == 0);

    queue.enqueue(40);
    queue.enqueue(50);
    queue.dequeue();
    assert(queue.front() == 50);
    queue.enqueue(60);
    assert(queue.getSize() == 2);
    queue.dequeue();
    queue.dequeue();
    assert(queue.isEmpty());

    for (int i = 1; i <= 10; i++)
    {
        queue.enqueue(i * 10);
    }
    assert(queue.getSize() == 10);
    assert(queue.front() == 10);

    for (int i = 1; i <= 10; i++)
    {
        assert(queue.front() == i * 10);
        queue.dequeue();
    }

    assert(queue.isEmpty());

    cout << "All tests passed!\n";
}

int main()
{
    Queue myQueue(3);
    testQueue(myQueue);
    return 0;
}
