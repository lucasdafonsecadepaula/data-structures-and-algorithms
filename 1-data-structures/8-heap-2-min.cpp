#include <iostream>
#include <cassert>
using namespace std;

class MinHeap
{
private:
    int *heap;
    int size;
    int capacity;

    int getParent(int index) const { return (index - 1) / 2; }
    int getLeftChild(int index) const { return (index * 2) + 1; }
    int getRightChild(int index) const { return (index * 2) + 2; }

    void heapifyUp(int index)
    {
        while (index > 0)
        {
            int parentIndex = getParent(index);
            if (heap[index] >= heap[parentIndex])
                break;
            swap(heap[index], heap[parentIndex]);
            index = parentIndex;
        }
    }

    void heapifyDown(int index)
    {
        while (true)
        {
            int leftChild = getLeftChild(index);
            int rightChild = getRightChild(index);
            int smallest = index;

            if (leftChild < size && heap[leftChild] < heap[smallest])
            {
                smallest = leftChild;
            }
            if (rightChild < size && heap[rightChild] < heap[smallest])
            {
                smallest = rightChild;
            }
            if (smallest == index)
                break;

            swap(heap[index], heap[smallest]);
            index = smallest;
        }
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
        if (size >= capacity)
            resize();
        heap[size] = value;
        heapifyUp(size);
        size++;
    }

    int extractMin()
    {
        if (size == 0)
            throw runtime_error("Heap is empty");

        int minVal = heap[0];
        heap[0] = heap[size - 1];
        size--;
        if (size > 0)
            heapifyDown(0);
        return minVal;
    }

    int peekMin() const
    {
        if (size == 0)
            throw runtime_error("Heap is empty");
        return heap[0];
    }

    bool isEmpty() const { return size == 0; }
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
