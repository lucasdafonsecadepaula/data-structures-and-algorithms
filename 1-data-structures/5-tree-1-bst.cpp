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
        if (node == nullptr)
        {
            return new TreeNode(value);
        }

        if (value < node->data)
        {
            node->left = insertRecursive(node->left, value);
        }
        else if (value > node->data)
        {
            node->right = insertRecursive(node->right, value);
        }
        return node;
    }

    bool searchRecursive(TreeNode *node, int value) const
    {
        if (node == nullptr)
        {
            return false;
        }

        if (node->data == value)
        {
            return true;
        }

        return value < node->data ? searchRecursive(node->left, value) : searchRecursive(node->right, value);
    }

    TreeNode *findMin(TreeNode *node)
    {
        while (node->left != nullptr)
        {
            node = node->left;
        }
        return node;
    }

    TreeNode *removeRecursive(TreeNode *node, int value)
    {
        if (node == nullptr)
        {
            return nullptr;
        }

        if (value < node->data)
        {
            node->left = removeRecursive(node->left, value);
        }
        else if (value > node->data)
        {
            node->right = removeRecursive(node->right, value);
        }
        else
        {
            if (node->left == nullptr)
            {
                TreeNode *temp = node->right;
                delete node;
                return temp;
            }
            else if (node->right == nullptr)
            {
                TreeNode *temp = node->left;
                delete node;
                return temp;
            }

            TreeNode *temp = findMin(node->right);
            node->data = temp->data;
            node->right = removeRecursive(node->right, temp->data);
        }
        return node;
    }

    void destroyTree(TreeNode *node)
    {
        if (node != nullptr)
        {
            destroyTree(node->left);
            destroyTree(node->right);
            delete node;
        }
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
