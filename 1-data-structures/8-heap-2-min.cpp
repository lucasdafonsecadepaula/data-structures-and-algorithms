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
        while(index > 0) {
            int parentIndex = getParent(index);
            if(heap[index] > heap[parentIndex]) break;
            int temp = heap[index];
            heap[index] = heap[parentIndex];
            heap[parentIndex] = temp;
            index = parentIndex;
        }
    }

    void heapifyDown(int index)
    {
        int leftChild, rightChild, smallest;

        while(index < size / 2) {
            leftChild = getLeftChild(index); 
            rightChild = getLeftChild(index);
            smallest = index;

            if(leftChild < size && heap[smallest] > heap[leftChild]) {
                smallest = leftChild;
            }
            if(rightChild < size && heap[smallest] > heap[rightChild]) {
                smallest = rightChild;
            }
            if(smallest == index) break;

            int temp = heap[index];
            heap[index] = heap[smallest];
            heap[smallest] = temp;

            index = smallest;
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
    MinHeap(int cap = 10) : capacity(cap), size(0), heap(new int[capacity]) {}
    ~MinHeap() {
        delete[] heap;
    } 

    void insert(int value)
    {
        if(size >= capacity) resize();

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
        if(size > 0) heapifyDown(0);
        return minVal;
    }

    int peekMin() const
    {
        if (size == 0)
            throw runtime_error("Heap is empty");
            
        return heap[0]; 
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
