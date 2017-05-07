#include <stdio.h>
#include <iostream>

using namespace std;

typedef struct bTreeNode {
	int data;
	struct bTreeNode *left;
	struct bTreeNode *right;
} bTreeNode;

void addTreeNode(bTreeNode *&node, int data)
{
	if(node == NULL) {
		bTreeNode *pNode = new bTreeNode();
		pNode->data = data;
		pNode->left = NULL;
		pNode->right = NULL;
		node = pNode;
	} else {
		if (data < node->data) {
			addTreeNode(node->left, data);
		} else if (data > node->data) {
			addTreeNode(node->right, data);
		} else {
			cout<<"the data is overlapping"<<endl;
		}
	}
}

void convertNode(bTreeNode *node, bTreeNode *&lastNodeofList)
{
	if (node == NULL) {
		return;
	}
	bTreeNode *pCurrent = node;
	if (pCurrent->left != NULL) {
		convertNode(pCurrent->left, lastNodeofList);
	}
	pCurrent->left = lastNodeofList;
	if (lastNodeofList!= NULL) {
		lastNodeofList->right = pCurrent;
	}
	lastNodeofList = pCurrent;
	if (pCurrent->right != NULL) {
		convertNode(pCurrent->right, lastNodeofList);
	}
}

bTreeNode *getList(bTreeNode *root)
{
	bTreeNode *lastNodeofList = NULL;
	convertNode(root, lastNodeofList);
	bTreeNode *headofList = lastNodeofList;
	while(headofList !=NULL && headofList->left != NULL) {
		headofList = headofList->left;
	}
	return headofList;
}

int main()
{
	bTreeNode *root = NULL;
/*	for (int i= 6;i>1;i++) {
		addTreeNode(root, i);
	}
*/
	int datas[6] = {24,15,27,4,43,87};
	for (int i=0; i<6;i++) {
		addTreeNode(root, datas[i]);
	}
	bTreeNode *headofList = getList(root);
	while(headofList!=NULL) {
		cout<<headofList->data<<endl;
		headofList = headofList->right;
	}
	return 0;
}
