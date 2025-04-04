#include <iostream>
#include <cassert>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node(int value) : data(value), next(nullptr) {};
};

class Graph
{
private:
    int vertices;
    Node **adjList;

    void delRec(Node *node)
    {
        if (node == nullptr)
            return;
        delRec(node->next);
        delete node;
    }

public:
    Graph(int v) : vertices(v), adjList(new Node *[vertices])
    {
        for (int i = 0; i < vertices; i++)
        {
            adjList[i] = nullptr;
        }
    }
    ~Graph()
    {
        for (int i = 0; i < vertices; i++)
        {
            delRec(adjList[i]);
        }
        delete[] adjList;
    }

    void addEdge(int src, int dest)
    {
        if (src < 0 || src >= vertices || dest < 0 || dest >= vertices || src == dest)
        {
            return;
        }

        Node *temp = adjList[src];
        while (temp != nullptr)
        {
            if (temp->data == dest)
                return;
            temp = temp->next;
        }

        Node *newNodeSrc = new Node(dest);
        newNodeSrc->next = adjList[src];
        adjList[src] = newNodeSrc;

        Node *newNodeDest = new Node(src);
        newNodeDest->next = adjList[dest];
        adjList[dest] = newNodeDest;
    }

    void removeEdge(int src, int dest)
    {
        if (src < 0 || src >= vertices || dest < 0 || dest >= vertices)
        {
            return;
        }

        Node *cur = adjList[src];
        Node *prev = nullptr;
        while (cur != nullptr && cur->data != dest)
        {
            prev = cur;
            cur = cur->next;
        }
        if (cur != nullptr)
        {
            if (prev == nullptr)
                adjList[src] = cur->next;
            else
                prev->next = cur->next;
            delete cur;
        }

        cur = adjList[dest];
        prev = nullptr;
        while (cur != nullptr && cur->data != src)
        {
            prev = cur;
            cur = cur->next;
        }
        if (cur != nullptr)
        {
            if (prev == nullptr)
                adjList[dest] = cur->next;
            else
                prev->next = cur->next;
            delete cur;
        }
    }

    bool hasEdge(int src, int dest) const
    {
        if (src < 0 || src >= vertices || dest < 0 || dest >= vertices)
        {
            return false;
        }
        Node *cur = adjList[src];
        while (cur != nullptr)
        {
            if (cur->data == dest)
                return true;
            cur = cur->next;
        }
        return false;
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

void testGraph(Graph &graph)
{
    graph.addEdge(0, 1);
    graph.addEdge(0, 2);
    graph.addEdge(1, 3);
    graph.addEdge(2, 3);
    graph.addEdge(3, 4);

    assert(graph.hasEdge(0, 1));
    assert(graph.hasEdge(1, 0));
    assert(graph.hasEdge(1, 3));
    assert(graph.hasEdge(3, 1));
    assert(graph.hasEdge(2, 3));
    assert(graph.hasEdge(3, 2));
    assert(graph.hasEdge(3, 4));
    assert(graph.hasEdge(4, 3));

    assert(!graph.hasEdge(0, 4));
    assert(!graph.hasEdge(1, 4));

    graph.removeEdge(1, 3);
    assert(!graph.hasEdge(1, 3));
    assert(!graph.hasEdge(3, 1));

    graph.removeEdge(1, 3);
    assert(!graph.hasEdge(1, 3));
    assert(!graph.hasEdge(3, 1));

    graph.addEdge(2, 2);
    assert(!graph.hasEdge(2, 2));

    graph.addEdge(-1, 3);
    graph.addEdge(5, 3);
    assert(!graph.hasEdge(-1, 3));
    assert(!graph.hasEdge(5, 3));

    graph.removeEdge(-1, 3);
    graph.removeEdge(5, 3);
}

int main()
{
    Graph myGraph(5);
    testGraph(myGraph);
    cout << "All tests passed!\n";
    return 0;
}
