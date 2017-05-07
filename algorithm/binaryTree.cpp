#include <stdio.h>
#include <stdlib.h>
#include <queue>
using namespace std;

typedef struct binaryTreeNode {
	int elem;
	struct binaryTreeNode *left;
	struct binaryTreeNode *right;
} binaryTreeNode;

void addTreeNode(binaryTreeNode *&node, int elem)
{
	if (node == NULL) {
		binaryTreeNode *pNode = (binaryTreeNode*)malloc(sizeof(binaryTreeNode));
		pNode->elem = elem;
		pNode->left = NULL;
		pNode->right = NULL;
		node = pNode;
	} else {
		if (elem < node->elem) {
			addTreeNode(node->left, elem);
		} else if(elem > node->elem) {
			addTreeNode(node->right, elem);
		} else {
			printf("elem is overlapping\n");
		}
	}
}
		
void preOrderTree(binaryTreeNode *root)
{
	if(NULL != root) {
		printf("%d ", root->elem);
		preOrderTree(root->left);
		preOrderTree(root->right);
	}
}

void inOrderTree(binaryTreeNode *root)
{
	if(NULL != root) {
		inOrderTree(root->left);
		printf("%d ", root->elem);
		inOrderTree(root->right);
	}
}

void postOrderTree(binaryTreeNode *root)
{
	if(NULL != root) {
	   postOrderTree(root->left);
		postOrderTree(root->right);
		printf("%d ", root->elem);
	}
}

void levelOrderTree(binaryTreeNode *root)
{
	if (NULL == root) {
		return;
	}
	queue<binaryTreeNode *> q;
	q.push(root);
	while (!q.empty()) {
		binaryTreeNode *pNode = q.front();
		q.pop();
		printf("%d ", pNode->elem);
		if (pNode->left) {
			q.push(pNode->left);
		}
		if (pNode->right) {
			q.push(pNode->right);
		}
	}
}

int main()
{	
	binaryTreeNode *root = NULL;
	int elems[6] = {24, 15, 27, 4, 43, 87};
	for (int i=0; i< 6;i++) {
		addTreeNode(root, elems[i]);
	}
	preOrderTree(root);
	printf("\n");
	inOrderTree(root);
	printf("\n");
	postOrderTree(root);
	printf("\n");
	levelOrderTree(root);
	printf("\n");
	return 0;
}
	
