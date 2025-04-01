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
    }

public:
    Graph(int v)
    {
    }
    ~Graph()
    {
    }

    void addEdge(int src, int dest)
    {
    }

    void removeEdge(int src, int dest)
    {
    }

    bool hasEdge(int src, int dest) const
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
