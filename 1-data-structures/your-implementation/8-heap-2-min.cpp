#include <iostream>
#include <vector>
#include <cassert>

using namespace std;

class MinHeap
{
private:
    int *heap;
    int size;
    int capacity;

    int getParent(int index) const {
    }

    int getLeftChild(int index) const {
    }

    int getRightChild(int index) const {
    }

    void heapifyUp(int index)
    {
    }

    void heapifyDown(int index)
    {
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
    MinHeap(int cap = 10) : capacity(cap), size(0), heap(new int[capacity]) {}
    ~MinHeap() {
        delete[] heap;
    } 

    void insert(int value)
    {
    }

    int extractMin()
    {
    }

    int peekMin() const
    {
    }

    void printHeap() const
    {
        std::cout << "Min Heap: ";
        for (int i = 0; i < size; i++)
        {
            std::cout << heap[i] << " ";
        }
        std::cout << std::endl;
    }
};

void testMinHeap(MinHeap &heap)
{
    heap.insert(30);
    heap.insert(20);
    heap.insert(5);
    heap.insert(10);

    assert(heap.peekMin() == 5);
    assert(heap.extractMin() == 5);
    assert(heap.peekMin() == 10);
}

int main()
{
    try
    {
        MinHeap myHeap;
        testMinHeap(myHeap);
        myHeap.printHeap();
        std::cout << "All tests passed!\n";
    }
    catch (const std::exception &e)
    {
        std::cout << "Exception: " << e.what() << std::endl;
    }
    return 0;
}
