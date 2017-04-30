#include <iostream>
#include <deque>
using namespace std;

struct BTreeNode{
	int data;
	BTreeNode* left;
	BTreeNode* right;
};

void addBTreeNode(BTreeNode *&root, int data)
{
	if(root == NULL) {
		BTreeNode *pNode = new BTreeNode();
		pNode->data = data;
		pNode->left = NULL;
		pNode->right = NULL;
		root = pNode;
	} else {
		if (root->data > data) {
			addBTreeNode(root->left, data);
		} else if (root->data < data) {
			addBTreeNode(root->right, data);
		} else {
			cout<<"data overlapping"<<endl;
		}
	}
}

void printFromTopToBottom(BTreeNode *root)
{
	if (NULL == root) {
		return;
	}
	deque<BTreeNode *> deque1;
	deque1.push_back(root);
	while(deque1.size()) {
		BTreeNode *node = deque1.front();
		deque1.pop_front();
		cout<<node->data<<' ';
		if(node->left) {
			deque1.push_back(node->left);
		}
		if(node->right) {
			deque1.push_back(node->right);
		}
	}
}

int main()
{
	int a[6] = {24,15,27,4,26,43};
	BTreeNode* root = NULL;
	for (int i=0;i<6;i++) {
		addBTreeNode(root, a[i]);
	}
	printFromTopToBottom(root);
}

