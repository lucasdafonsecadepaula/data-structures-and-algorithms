#include <iostream>
#include <cassert>
#include <vector>
using namespace std;

class TreeNode
{
public:
    int data;
    TreeNode *left;
    TreeNode *right;
    int height;

    TreeNode(int value) : data(value), left(nullptr), right(nullptr), height(1) {}
};

class AVLTree
{
private:
    TreeNode *root;

    int getHeight(TreeNode *node)
    {
        return node ? node->height : 0;
    }

    int getBalanceFactor(TreeNode *node)
    {
        return node ? getHeight(node->left) - getHeight(node->right) : 0;
    }

    TreeNode *rotateRight(TreeNode *y)
    {
        TreeNode *x = y->left;
        TreeNode *T = x->right;

        x->right = y;
        y->left = T;

        y->height = max(getHeight(y->left), getHeight(y->right)) + 1;
        x->height = max(getHeight(x->left), getHeight(x->right)) + 1;

        return x;
    }

    TreeNode *rotateLeft(TreeNode *x)
    {
        TreeNode *y = x->right;
        TreeNode *T = y->left;

        y->left = x;
        x->right = T;

        x->height = max(getHeight(x->left), getHeight(x->right)) + 1;
        y->height = max(getHeight(y->left), getHeight(y->right)) + 1;

        return y;
    }

    TreeNode *insertRecursive(TreeNode *node, int value)
    {
        if (!node)
            return new TreeNode(value);

        if (value < node->data)
            node->left = insertRecursive(node->left, value);
        else if (value > node->data)
            node->right = insertRecursive(node->right, value);
        else
            return node;

        node->height = max(getHeight(node->left), getHeight(node->right)) + 1;

        int balance = getBalanceFactor(node);

        if (balance > 1 && value < node->left->data)
            return rotateRight(node);

        if (balance < -1 && value > node->right->data)
            return rotateLeft(node);

        if (balance > 1 && value > node->left->data)
        {
            node->left = rotateLeft(node->left);
            return rotateRight(node);
        }

        if (balance < -1 && value < node->right->data)
        {
            node->right = rotateRight(node->right);
            return rotateLeft(node);
        }

        return node;
    }

    TreeNode *findMin(TreeNode *node)
    {
        while (node->left)
            node = node->left;
        return node;
    }

    TreeNode *removeRecursive(TreeNode *node, int value)
    {
        if (!node)
            return nullptr;

        if (value < node->data)
            node->left = removeRecursive(node->left, value);
        else if (value > node->data)
            node->right = removeRecursive(node->right, value);
        else
        {
            if (!node->left || !node->right)
            {
                TreeNode *temp = node->left ? node->left : node->right;
                delete node;
                return temp;
            }
            else
            {
                TreeNode *temp = findMin(node->right);
                node->data = temp->data;
                node->right = removeRecursive(node->right, temp->data);
            }
        }

        if (!node)
            return nullptr;

        node->height = max(getHeight(node->left), getHeight(node->right)) + 1;
        int balance = getBalanceFactor(node);

        if (balance > 1 && getBalanceFactor(node->left) >= 0)
            return rotateRight(node);

        if (balance > 1 && getBalanceFactor(node->left) < 0)
        {
            node->left = rotateLeft(node->left);
            return rotateRight(node);
        }

        if (balance < -1 && getBalanceFactor(node->right) <= 0)
            return rotateLeft(node);

        if (balance < -1 && getBalanceFactor(node->right) > 0)
        {
            node->right = rotateRight(node->right);
            return rotateLeft(node);
        }

        return node;
    }

    bool searchRecursive(TreeNode *node, int value) const
    {
        if (!node)
            return false;

        if (node->data == value)
            return true;

        return value < node->data ? searchRecursive(node->left, value) : searchRecursive(node->right, value);
    }

    void inOrderTraversalVector(TreeNode *node, vector<int> &arr) const
    {
        if (node == nullptr)
            return;
        inOrderTraversalVector(node->left, arr);
        arr.push_back(node->data);
        inOrderTraversalVector(node->right, arr);
    }

    void destroyTree(TreeNode *node)
    {
        if (node)
        {
            destroyTree(node->left);
            destroyTree(node->right);
            delete node;
        }
    }

public:
    AVLTree() : root(nullptr) {}
    ~AVLTree()
    {
        destroyTree(root);
    }

    void insert(int value)
    {
        root = insertRecursive(root, value);
    }

    void remove(int value)
    {
        root = removeRecursive(root, value);
    }

    bool search(int value) const
    {
        return searchRecursive(root, value);
    }

    vector<int> inorder() const
    {
        vector<int> inOrderArr;
        inOrderTraversalVector(root, inOrderArr);
        return inOrderArr;
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

void testAVLTree()
{
    AVLTree tree;

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

    AVLTree tree1;
    tree1.insert(30);
    tree1.insert(20);
    tree1.insert(10);

    vector<int> inOrderShouldBe = {10, 20, 30};

    assert(tree1.inorder() == inOrderShouldBe);

    assert(tree1.search(20));
    assert(tree1.search(10));
    assert(tree1.search(30));

    AVLTree tree2;
    tree2.insert(10);
    tree2.insert(20);
    tree2.insert(30);

    assert(tree2.inorder() == inOrderShouldBe);

    assert(tree2.search(10));
    assert(tree2.search(20));
    assert(tree2.search(30));

    AVLTree tree3;
    tree3.insert(30);
    tree3.insert(10);
    tree3.insert(20);

    assert(tree3.inorder() == inOrderShouldBe);

    assert(tree3.search(10));
    assert(tree3.search(20));
    assert(tree3.search(30));

    AVLTree tree4;
    tree4.insert(10);
    tree4.insert(30);
    tree4.insert(20);

    assert(tree4.inorder() == inOrderShouldBe);

    assert(tree4.search(10));
    assert(tree4.search(20));
    assert(tree4.search(30));

    tree.remove(20);
    assert(!tree.search(20));

    tree.remove(30);
    assert(!tree.search(30));

    tree.remove(50);
    assert(!tree.search(50));

    tree.insert(25);
    assert(tree.search(25));

    tree.insert(25);
    assert(tree.search(25));

    tree.remove(70);
    assert(!tree.search(70));

    tree.remove(40);
    assert(!tree.search(40));

    tree.remove(60);
    assert(!tree.search(60));

    tree.remove(80);
    assert(!tree.search(80));

    tree.insert(90);
    assert(tree.search(90));

    vector<int> shouldBeSorted = tree.inorder();
    for (int i = 1; i < shouldBeSorted.size(); i++)
    {
        assert(shouldBeSorted[i - 1] < shouldBeSorted[i]);
    }

    cout << "All AVL Tree tests passed!\n";
}

int main()
{
    testAVLTree();
    return 0;
}
