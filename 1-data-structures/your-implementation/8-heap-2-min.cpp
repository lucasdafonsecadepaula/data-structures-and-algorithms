#include <iostream>
#include <cassert>
using namespace std;

class MinHeap
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
    MinHeap(int cap = 10) : capacity(cap), size(0), heap(new int[capacity]) {}
    ~MinHeap() { delete[] heap; }

    void insert(int value)
    {
    }

    int extractMin()
    {
    }

    int peekMin() const
    {
    }

    bool isEmpty() const {}
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

void testMinHeap(MinHeap &heap)
{
    heap.insert(30);
    heap.insert(20);
    heap.insert(5);
    heap.insert(10);
    heap.insert(1);
    heap.insert(40);
    heap.insert(3);

    assert(heap.peekMin() == 1);

    assert(heap.extractMin() == 1);
    assert(heap.extractMin() == 3);
    assert(heap.extractMin() == 5);
    assert(heap.extractMin() == 10);
    assert(heap.extractMin() == 20);
    assert(heap.extractMin() == 30);
    assert(heap.extractMin() == 40);

    assert(heap.isEmpty());

    try
    {
        heap.extractMin();
        assert(false);
    }
    catch (const runtime_error &e)
    {
        assert(string(e.what()) == "Heap is empty");
    }
}

int main()
{
    try
    {
        MinHeap heap;
        testMinHeap(heap);
        cout << "All tests passed!\n";
    }
    catch (const exception &e)
    {
        cout << "Exception: " << e.what() << endl;
    }
    return 0;
}
