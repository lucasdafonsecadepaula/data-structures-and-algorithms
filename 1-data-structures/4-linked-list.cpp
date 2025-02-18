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
            std::cout << "List is empty, nothing to remove.\n";
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
        else
        {
            std::cout << "Value " << value << " not found in the linked-list.\n";
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

    void print() const
    {
        std::cout << "Printing linked list: ";
        Node *cur = head;
        while (cur != nullptr)
        {
            std::cout << cur->data << " -> ";
            cur = cur->next;
        }
        std::cout << "nullptr\n";
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
