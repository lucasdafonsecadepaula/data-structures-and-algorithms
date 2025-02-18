#include <iostream>
#include <cassert>

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

    void printAdjList() const
    {
        std::cout << "Adjacency List:" << std::endl;
        for (int i = 0; i < vertices; i++)
        {
            std::cout << "Vertex " << i << ":";
            Node *cur = adjList[i];
            while (cur != nullptr)
            {
                std::cout << " " << cur->data;
                cur = cur->next;
            }
            std::cout << std::endl;
        }
    }

    void printAdjMatrix() const
    {
        std::cout << "Adjacency Matrix:" << std::endl;
        for (int i = 0; i < vertices; i++)
        {
            for (int j = 0; j < vertices; j++)
            {
                std::cout << (hasEdge(i, j) ? "1 " : "0 ");
            }
            std::cout << std::endl;
        }
    }
};

void testGraph(Graph &graph)
{
    graph.addEdge(0, 1);
    graph.addEdge(0, 2);
    graph.addEdge(1, 3);
    graph.addEdge(2, 3);
    graph.addEdge(3, 4);

    assert(graph.hasEdge(0, 1));
    assert(graph.hasEdge(1, 3));
    assert(!graph.hasEdge(0, 4));

    graph.removeEdge(1, 3);
    assert(!graph.hasEdge(1, 3));
}

int main()
{
    try
    {
        Graph myGraph(5);
        testGraph(myGraph);
        myGraph.printAdjList();
        myGraph.printAdjMatrix();
        std::cout << "All tests passed!\n";
    }
    catch (const std::exception &e)
    {
        std::cout << "Exception: " << e.what() << std::endl;
    }
    return 0;
}
