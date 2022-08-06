#include <iostream>
using namespace std;

class BST {
private:
	int data;
	BST *left, *right;

public:
	BST();
	BST(int);

	BST* Insert(BST*, int);

	void inOrder(BST*);
	void preOrder(BST*);
	void postOrder(BST*);
};

BST::BST(): data(0), left(NULL), right(NULL){}

BST::BST(int value)
{
	data = value;
	left = right = NULL;
}

BST* BST::Insert(BST* root, int value)
{
	if (!root) {
		return new BST(value);
	}

	if (value > root->data) {
		root->right = Insert(root->right, value);
	}
	else {
		root->left = Insert(root->left, value);
	}

	return root;
}

void BST::inOrder(BST* root)
{
	if (!root) {
		return;
	}

	inOrder(root->left);
	cout << root->data << endl;
	inOrder(root->right);
}

void BST::preOrder(BST* root)
{
	if (!root) {
		return;
	}

	cout << root->data << endl;
	inOrder(root->left);
	inOrder(root->right);
}

void BST::postOrder(BST* root)
{
	if (!root) {
		return;
	}
	inOrder(root->left);
	inOrder(root->right);
	cout << root->data << endl;
}

int main()
{
	BST obj, *root = NULL;
	root = obj.Insert(root, 50);
    system("CLS");
	obj.Insert(root, 30);
	obj.Insert(root, 20);
	obj.Insert(root, 40);
	obj.Insert(root, 70);
	obj.Insert(root, 60);
	obj.Insert(root, 80);

    cout << "Inorder    : " << endl;
	obj.inOrder(root);
    cout << "\nPostorder  : " << endl;
    obj.postOrder(root);
    cout << "\nPreorder   : " << endl;
    obj.preOrder(root);

    cin.get();
	return 0;
}