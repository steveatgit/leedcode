wqu-m01:code wqu$ ./a.out 
5 6 7 8 9 10 11 
11 10 9 8 7 6 5 
wqu-m01:code wqu$ !c
cat test.cpp 
#include <iostream>  
using namespace std;  

struct BinaryTreeNode
{
	BinaryTreeNode *left;
	BinaryTreeNode *right;
	int elem;
};
void addBinaryTree(BinaryTreeNode *&root, int elem)
{
	if (NULL == root) {
		BinaryTreeNode *pNode = new BinaryTreeNode();
		pNode->elem = elem;
		pNode->left = NULL;
		pNode->right = NULL;
		root = pNode;
	}
	else {
		if (elem < root->elem) {
			addBinaryTree(root->left, elem);
		}
		else if (elem > root->elem) {
			addBinaryTree(root->right, elem);
		}
		else {
			cout << "overlapping." << endl;
		}
	}
}
void inOrder(BinaryTreeNode* root)
{
	if (NULL == root) {
		return;
	}
	inOrder(root->left);
	cout << root->elem << " ";
	inOrder(root->right);
}
void mirrorBTreeNode(BinaryTreeNode *&root)
{
	if(NULL == root) {
		return;
	}
	BinaryTreeNode *tmp = root->left;
	root->left = root->right;
	root->right = tmp;
	if(root->left) {
		mirrorBTreeNode(root->left);
	}
	if(root->right) {
		mirrorBTreeNode(root->right);
	}
}
int main()
{
	BinaryTreeNode *root = NULL;
	int elems[7] = { 8, 6, 10, 5,7,9,11 };
	for (int i = 0; i< 7; i++) {
		addBinaryTree(root, elems[i]);
	}
	inOrder(root);
	cout << endl;
	mirrorBTreeNode(root);
	inOrder(root);
	cout << endl;
	return 0;
}
