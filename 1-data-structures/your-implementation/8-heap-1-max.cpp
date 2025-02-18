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
    Heap(int cap = 10) : capacity(cap), size(0), heap(new int[capacity]) {}
    ~Heap()
    {
        delete[] heap;
    }

    void insert(int value)
    {
    }

    int extractMax()
    {
    }

    int peekMax() const
    {
    }

    void printHeap() const
    {
        cout << "Heap: ";
        for (int i = 0; i < size; i++)
        {
            cout << heap[i] << " ";
        }
        cout << endl;
    }
};

void testHeap(Heap &heap)
{
    heap.insert(10);
    heap.insert(20);
    heap.insert(5);
    heap.insert(30);

    assert(heap.peekMax() == 30);
    assert(heap.extractMax() == 30);
    assert(heap.peekMax() == 20);
}

int main()
{
    try
    {
        Heap myHeap;
        testHeap(myHeap);
        myHeap.printHeap();
        cout << "All tests passed!\n";
    }
    catch (const exception &e)
    {
        cout << "Exception: " << e.what() << endl;
    }
    return 0;
}
