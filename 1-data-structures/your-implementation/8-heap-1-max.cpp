#include <iostream>
#include <cassert>
using namespace std;

class Heap
{
private:
    int *heap;
    int size;
    int capacity;

    void heapifyUp(int index)
    {
    }

    void heapifyDown(int index)
    {
    }

    void resize()
    {
        capacity *= 2;
        int *newHeap = new int[capacity];
        for (int i = 0; i < size; i++)
        {
            newHeap[i] = heap[i];
        }
        delete[] heap;
        heap = newHeap;
    }

public:
    Heap(int cap = 10) {}
    ~Heap() {}

    void insert(int value)
    {
    }

    int extractMax()
    {
    }

    int peekMax() const
    {
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

void testHeap(Heap &heap)
{
    heap.insert(10);
    heap.insert(20);
    heap.insert(5);
    heap.insert(30);
    heap.insert(25);
    heap.insert(40);

    assert(heap.peekMax() == 40);

    assert(heap.extractMax() == 40);
    assert(heap.peekMax() == 30);

    assert(heap.extractMax() == 30);
    assert(heap.peekMax() == 25);

    assert(heap.extractMax() == 25);
    assert(heap.extractMax() == 20);
    assert(heap.extractMax() == 10);
    assert(heap.extractMax() == 5);

    heap.insert(50);
    heap.insert(15);
    assert(heap.peekMax() == 50);
    heap.insert(60);
    assert(heap.peekMax() == 60);

    for (int i = 0; i < 20; i++)
    {
        heap.insert(i * 5);
    }
    assert(heap.peekMax() == 95);
}

int main()
{
    Heap myHeap;
    testHeap(myHeap);
    cout << "All tests passed!\n";
    return 0;
}
