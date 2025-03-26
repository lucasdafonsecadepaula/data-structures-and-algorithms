#include <iostream>
#include <cassert>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

    Node(int value) : data(value), next(nullptr) {}
};

class LinkedList
{
private:
    Node *head;

public:
    LinkedList() : head(nullptr) {}

    ~LinkedList()
    {
    }

    void insertFront(int value)
    {
    }

    void insertBack(int value)
    {
    }

    void remove(int value)
    {
    }

    bool contains(int value) const
    {
    }

    int size() const
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

void testLinkedList(LinkedList &list)
{
    assert(list.size() == 0);
    assert(!list.contains(10));

    list.insertFront(10);
    assert(list.size() == 1);
    assert(list.contains(10));

    list.insertBack(30);
    assert(list.size() == 2);
    assert(list.contains(30));

    list.insertFront(20);
    assert(list.size() == 3);
    assert(list.contains(20));

    list.insertBack(40);
    assert(list.size() == 4);
    assert(list.contains(40));

    list.remove(20);
    assert(list.size() == 3);
    assert(!list.contains(20));

    list.remove(10);
    assert(list.size() == 2);
    assert(!list.contains(10));

    list.remove(40);
    assert(list.size() == 1);
    assert(!list.contains(40));

    list.remove(30);
    assert(list.size() == 0);
    assert(!list.contains(30));

    list.remove(50);
    assert(list.size() == 0);

    list.insertFront(60);
    list.insertBack(70);
    list.insertFront(50);
    assert(list.size() == 3);
    assert(list.contains(50));
    assert(list.contains(60));
    assert(list.contains(70));

    list.remove(999);
    assert(list.size() == 3);

    cout << "All tests passed!\n";
}

int main()
{
    LinkedList myList;
    testLinkedList(myList);
    return 0;
}
