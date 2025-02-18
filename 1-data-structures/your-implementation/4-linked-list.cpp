#include <iostream>
#include <cassert>

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

    void delRec(Node *node)
    {
    }

    bool helperContains(Node *node, int value)
    {
    }

    int helperSize(Node *node)
    {
    }

public:
    LinkedList() {}

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

    bool contains(int value)
    {
    }

    int size()
    {
    }

    void print() const
    {
    }
};

void testLinkedList(LinkedList &list)
{
    list.insertFront(10);
    list.insertFront(20);
    list.insertBack(30);

    assert(list.size() == 3);
    assert(list.contains(10));
    assert(list.contains(20));
    assert(list.contains(30));

    list.remove(20);
    assert(list.size() == 2);
    assert(!list.contains(20));

    list.remove(10);
    assert(!list.contains(10));

    list.remove(30);
    assert(list.size() == 0);
}

int main()
{
    LinkedList myList;
    testLinkedList(myList);
    std::cout << "All tests passed!\n";
    return 0;
}
