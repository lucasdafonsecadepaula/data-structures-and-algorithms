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
        while (head != nullptr)
        {
            Node *temp = head->next;
            delete head;
            head = temp;
        }
    }

    void insertFront(int value)
    {
        Node *newNode = new Node(value);
        newNode->next = head;
        head = newNode;
    }

    void insertBack(int value)
    {
        Node *newNode = new Node(value);

        if (head == nullptr)
        {
            head = newNode;
            return;
        }

        Node *cur = head;
        while (cur->next != nullptr)
        {
            cur = cur->next;
        }

        cur->next = newNode;
    }

    void remove(int value)
    {
        if (head == nullptr)
        {
            return;
        }

        if (head->data == value)
        {
            Node *temp = head;
            head = head->next;
            delete temp;
            return;
        }

        Node *cur = head;
        while (cur->next != nullptr && cur->next->data != value)
        {
            cur = cur->next;
        }

        if (cur->next != nullptr)
        {
            Node *temp = cur->next;
            cur->next = cur->next->next;
            delete temp;
        }
    }

    bool contains(int value) const
    {
        Node *cur = head;
        while (cur != nullptr)
        {
            if (cur->data == value)
            {
                return true;
            }
            cur = cur->next;
        }
        return false;
    }

    int size() const
    {
        int count = 0;
        Node *cur = head;
        while (cur != nullptr)
        {
            cur = cur->next;
            count++;
        }
        return count;
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

    std::cout << "All tests passed!\n";
}

int main()
{
    LinkedList myList;
    testLinkedList(myList);
    return 0;
}
