#include <iostream>
#include <cassert>
using namespace std;

class TreeNode
{
public:
    int data;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int value) : data(value), left(nullptr), right(nullptr) {}
};

class BST
{
private:
    TreeNode *root;

    TreeNode *insertRecursive(TreeNode *node, int value)
    {
    }

    bool searchRecursive(TreeNode *node, int value) const
    {
    }

    TreeNode *findMin(TreeNode *node)
    {
    }

    TreeNode *removeRecursive(TreeNode *node, int value)
    {
    }

    void destroyTree(TreeNode *node)
    {
    }

public:
    BST() : root(nullptr) {}
    ~BST()
    {
        destroyTree(root);
    }

    void insert(int value)
    {
        root = insertRecursive(root, value);
    }

    bool search(int value) const
    {
        return searchRecursive(root, value);
    }

    void remove(int value)
    {
        root = removeRecursive(root, value);
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

void testBST()
{
    BST tree;

    assert(!tree.search(10));

    tree.remove(10);

    tree.insert(50);
    tree.insert(30);
    tree.insert(70);
    tree.insert(20);
    tree.insert(40);
    tree.insert(60);
    tree.insert(80);

    assert(tree.search(50));
    assert(tree.search(30));
    assert(tree.search(70));
    assert(tree.search(20));
    assert(tree.search(40));
    assert(tree.search(60));
    assert(tree.search(80));

    assert(!tree.search(100));

    tree.remove(20);
    assert(!tree.search(20));

    tree.remove(30);
    assert(!tree.search(30));

    tree.remove(50);
    assert(!tree.search(50));

    assert(tree.search(40));
    assert(tree.search(60));
    assert(tree.search(70));
    assert(tree.search(80));

    tree.remove(100);
}

int main()
{
    testBST();
    cout << "All BST tests passed!\n";
    return 0;
}
