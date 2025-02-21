#include <iostream>
#include <queue>
#include <vector>
#include <cassert>
using namespace std;

struct TreeNode
{
    int data;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int val) : data(val), left(nullptr), right(nullptr) {}
};

void preOrderTraversal(TreeNode *tree, vector<int> &arr)
{
}

void inOrderTraversal(TreeNode *tree, vector<int> &arr)
{
}

void posOrderTraversal(TreeNode *tree, vector<int> &arr)
{
}

bool breadthFirstSearch(TreeNode *tree, int value, vector<int> &arr)
{
}

bool depthFirstSearch(TreeNode *tree, int value, vector<int> &arr)
{
}

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

int main()
{
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(7);

    //      1
    //    2   3
    //   4 5 6 7

    vector<int> preOrderTraversalArr;
    vector<int> preOrderTraversalArrExpected = {1, 2, 4, 5, 3, 6, 7};
    preOrderTraversal(root, preOrderTraversalArr);
    assert(preOrderTraversalArr == preOrderTraversalArrExpected);

    vector<int> inOrderTraversalArr;
    vector<int> inOrderTraversalArrExpected = {4, 2, 5, 1, 6, 3, 7};
    inOrderTraversal(root, inOrderTraversalArr);
    assert(inOrderTraversalArr == inOrderTraversalArrExpected);

    vector<int> posOrderTraversalArr;
    vector<int> posOrderTraversalArrExpected = {4, 5, 2, 6, 7, 3, 1};
    posOrderTraversal(root, posOrderTraversalArr);
    assert(posOrderTraversalArr == posOrderTraversalArrExpected);

    vector<int> bfsArr;
    vector<int> bfsArrExpected = {1, 2, 3};
    breadthFirstSearch(root, 3, bfsArr);
    assert(bfsArr == bfsArrExpected);

    vector<int> dfsArr;
    vector<int> dfsArrExpected = {1, 2, 4, 5, 3};
    depthFirstSearch(root, 3, dfsArr);
    assert(dfsArr == dfsArrExpected);

    delete root->left->left;
    delete root->left->right;
    delete root->right->left;
    delete root->right->right;
    delete root->left;
    delete root->right;
    delete root;
    cout << "All tests passed!\n";
    return 0;
}
