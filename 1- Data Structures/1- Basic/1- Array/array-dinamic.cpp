#include <iostream>

class DynamicArray {
private:
    int* arr;       // Pointer to the array
    int capacity;   // Total capacity of the array
    int size;       // Current number of elements in the array

    // Function to resize the array when it is full
    void resize() {
        capacity *= 2; // Double the capacity
        int* newArr = new int[capacity]; // Allocate new array

        // Copy elements from old array to new array
        for (int i = 0; i < size; i++) {
            newArr[i] = arr[i];
        }

        delete[] arr; // Free old array memory
        arr = newArr; // Point to the new array
    }

public:
    // Constructor
    DynamicArray(int cap = 2) { // Default capacity is 2
        capacity = cap;
        size = 0;
        arr = new int[capacity]; // Allocate memory
    }

    // Destructor
    ~DynamicArray() {
        delete[] arr; // Free allocated memory
    }

    // Function to add an element to the array
    void add(int element) {
        if (size >= capacity) {
            resize(); // Resize the array if full
        }
        arr[size++] = element; // Add element and increase size
    }

    // Function to display the array elements
    void display() const {
        for (int i = 0; i < size; i++) {
            std::cout << arr[i] << " ";
        }
        std::cout << std::endl;
    }

    // Function to get the current size of the array
    int getSize() const {
        return size;
    }
};

int main() {
    DynamicArray dynArr; // Create a dynamic array

    // Adding elements to the array
    dynArr.add(10);
    dynArr.add(20);
    dynArr.add(30);
    dynArr.add(40);
    dynArr.add(50); // Adding more elements

    // Display the elements in the array
    std::cout << "Array elements: ";
    dynArr.display();

    return 0;
}
