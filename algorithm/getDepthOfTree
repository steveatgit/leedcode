
#include <iostream>
using namespace std;

struct BTreeNode{
	int data;
	BTreeNode* left;
	BTreeNode* right;
};

void addBTreeNode(BTreeNode *&root, int data)
{
	if (root == NULL) {
		BTreeNode *pNode = new BTreeNode();
		pNode->data = data;
		pNode->left = NULL;
		pNode->right = NULL;
		root = pNode;
	}
	else {
		if (root->data > data) {
			addBTreeNode(root->left, data);
		}
		else if (root->data < data) {
			addBTreeNode(root->right, data);
		}
		else {
			cout << "data overlapping" << endl;
		}
	}
}

int lenofBTree(BTreeNode *root)
{
	if (NULL == root) {
		return 0;
	}
	int nLeft = lenofBTree(root->left);
	int nRight = lenofBTree(root->right);
	return (nLeft > nRight) ? (nLeft + 1) : (nRight + 1);
}

int main()
{
	int a[6] = { 24, 15, 27, 4, 26, 43 };
	BTreeNode* root = NULL;
	for (int i = 0; i<6; i++) {
		addBTreeNode(root, a[i]);
	}
	cout << lenofBTree(root) << endl;
}
//3
