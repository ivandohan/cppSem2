#include <iostream>
using namespace std;

struct TNode {
    int nodeVal;
    TNode *left;
    TNode *right;
};

int main()
{
    TNode *root = new TNode();

    root->nodeVal = 3;
    root->left = new TNode();
    root->right = new TNode();

    root->left->nodeVal = 8;
    root->right->nodeVal = 5;

    cout << root->nodeVal << " "
        << root->left->nodeVal << " "
        << root->right->nodeVal << endl;

    return 0;
}