#include <iostream>
#include <cassert>
#include <queue>
#include <unordered_map>
#include <vector>
using namespace std;

/*
    Huffman Coding Implementation

    Text = "heelllllllo";

    Freq = { o: 1, l: 7, e: 2, h: 1 }

    HuffmanTree =  (*,11)
                    /   \
                (*,4)    (l,7)
                /   \
            (e,2)   (*,2)
                    /   \
                (o,1)  (h,1)

    HuffmanTable = { l: [1], h: [0, 1, 1], o: [0, 1, 0], e: [0, 0] }

    Encoded = [0, 1, 1, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 0, 1, 0]
*/

struct Node
{
    char c;
    int freq;
    Node *left;
    Node *right;
    Node(char c, int f, Node *left = nullptr, Node *right = nullptr) : c(c), freq(f), left(left), right(right) {}
};

struct Compare
{
    bool operator()(const Node *left, const Node *right)
    {
        return left->freq > right->freq;
    }
};

void encode(Node *root, vector<bool> bin, unordered_map<char, vector<bool>> &huffmanCode)
{
    if (!root)
        return;
    if (!root->right && !root->left)
    {
        huffmanCode[root->c] = bin;
        return;
    }
    vector<bool> leftBin = bin;
    leftBin.push_back(false);
    encode(root->left, leftBin, huffmanCode);

    vector<bool> rightBin = bin;
    rightBin.push_back(true);
    encode(root->right, rightBin, huffmanCode);
}

string decode(Node *root, vector<bool> encodedV)
{
    string decodedStr = "";
    Node *cur = root;
    for (auto c : encodedV)
    {
        cur = c ? cur->right : cur->left;
        if (!cur->left && !cur->right)
        {
            decodedStr += cur->c;
            cur = root;
        }
    }
    return decodedStr;
}

Node *buildHuffmanTree(const string &text, unordered_map<char, vector<bool>> &huffmanTable)
{
    unordered_map<char, int> freq;
    for (const auto c : text)
    {
        freq[c] += 1;
    }
    priority_queue<Node *, vector<Node *>, Compare> pq;
    for (auto pair : freq)
    {
        pq.push(new Node(pair.first, pair.second));
    }

    while (pq.size() > 1)
    {
        Node *left = pq.top();
        pq.pop();
        Node *right = pq.top();
        pq.pop();
        int sum = left->freq + right->freq;
        pq.push(new Node('\0', sum, left, right));
    }
    Node *root = pq.top();
    pq.pop();

    encode(root, {}, huffmanTable);
    return root;
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

void testHuffmanCoding()
{
    string text = "heelllllllo";
    unordered_map<char, vector<bool>> huffmanTable;
    Node *root = buildHuffmanTree(text, huffmanTable);

    vector<bool> encodedV;
    for (auto c : text)
    {
        for (auto b : huffmanTable[c])
        {
            encodedV.push_back(b);
        }
    }
    string decodedText = decode(root, encodedV);

    assert(decodedText == text);
    cout << "Test passed: Original text matches decoded text." << endl;
}

int main()
{
    testHuffmanCoding();
    return 0;
}
