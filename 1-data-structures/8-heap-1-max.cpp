#include <iostream>
#include <cassert>
using namespace std;

class Heap
{
private:
    int *heap;
    int size;
    int capacity;

    int getParent(int index) const {
        return (index - 1) / 2;
    }

    int getLeftChild(int index) const {
        return (index * 2) + 1;
    }

    int getRightChild(int index) const {
        return (index * 2) + 2;
    }

    void heapifyUp(int index)
    {
        while (index > 0)
        {
            int parent = getParent(index);
            if (heap[index] <= heap[parent]) break;
            int temp = heap[index];
            heap[index] = heap[parent];
            heap[parent] = temp;
            index = parent;
        }
    }

    void heapifyDown(int index)
    {
        int leftChild, rightChild, largest;
        while (index < size / 2)
        {
            leftChild = getLeftChild(index);
            rightChild = getRightChild(index);
            largest = index;

            if (leftChild < size && heap[leftChild] > heap[largest])
            {
                largest = leftChild;
            }
            if (rightChild < size && heap[rightChild] > heap[largest])
            {
                largest = rightChild;
            }
            if (largest == index) break;

            int temp = heap[index];
            heap[index] = heap[largest];
            heap[largest] = temp;
            index = largest;
        }
    }

    void resize() {
        capacity *= 2;
        int *newHeap = new int[capacity];
        for(int i = 0; i < size; i++) {
            newHeap[i] = heap[i];
        }
        delete[] heap;
        heap = newHeap;
    }

public:
    Heap(int cap = 10) : capacity(cap), size(0), heap(new int[capacity]) {}
    ~Heap()
    {
        delete[] heap;
    }

    void insert(int value)
    {
        if(size >= capacity) resize();
        heap[size] = value;
        size++;
        heapifyUp(size - 1);
    }

    int extractMax()
    {
        if (size == 0)
            throw runtime_error("Heap is empty");
        int maxValue = heap[0];
        heap[0] = heap[size - 1];
        size--;
        if (size > 0)
            heapifyDown(0);
        return maxValue;
    }

    int peekMax() const
    {
        if (size == 0)
            throw runtime_error("Heap is empty");
        return heap[0];
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

    try {
        heap.extractMax();
        assert(false);
    } catch (const runtime_error &) {}

    heap.insert(50);
    heap.insert(15);
    assert(heap.peekMax() == 50);
    heap.insert(60);
    assert(heap.peekMax() == 60);

    for (int i = 0; i < 20; i++) {
        heap.insert(i * 5);
    }
    assert(heap.peekMax() == 95);
}

int main()
{
    try
    {
        Heap myHeap;
        testHeap(myHeap);
        cout << "All tests passed!\n";
    }
    catch (const exception &e)
    {
        cout << "Exception: " << e.what() << endl;
    }
    return 0;
}
