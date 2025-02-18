#include <iostream>
#include <cassert>

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

        y->height = std::max(getHeight(y->left), getHeight(y->right)) + 1;
        x->height = std::max(getHeight(x->left), getHeight(x->right)) + 1;

        return x;
    }

    TreeNode *rotateLeft(TreeNode *x)
    {
        TreeNode *y = x->right;
        TreeNode *T = y->left;

        y->left = x;
        x->right = T;

        x->height = std::max(getHeight(x->left), getHeight(x->right)) + 1;
        y->height = std::max(getHeight(y->left), getHeight(y->right)) + 1;

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

        node->height = std::max(getHeight(node->left), getHeight(node->right)) + 1;

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

        node->height = std::max(getHeight(node->left), getHeight(node->right)) + 1;
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

    void inorderTraversal(TreeNode *node) const
    {
        if (node)
        {
            inorderTraversal(node->left);
            std::cout << node->data << " ";
            inorderTraversal(node->right);
        }
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

    void inorder() const
    {
        inorderTraversal(root);
        std::cout << std::endl;
    }
};

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

    tree.remove(20);
    assert(!tree.search(20));

    tree.remove(30);
    assert(!tree.search(30));

    tree.remove(50);
    assert(!tree.search(50));

    tree.inorder();
}

int main()
{
    testAVLTree();
    std::cout << "All AVL Tree tests passed!\n";
    return 0;
}
