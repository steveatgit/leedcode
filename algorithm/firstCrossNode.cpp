#include <iostream>
using namespace std;

struct ListNode{
int data;
ListNode *next;
};

int lenList(ListNode *node)
{
	if (NULL == node) {
		return 0;
	}
	int len = 0;
	while(node) {
		len++;
		node = node->next;
	}
	return len;
}

ListNode *firstCrossNode(ListNode *head1, ListNode *head2)
{
	int len1 = lenList(head1);
	int len2 = lenList(head2);
	cout<<len1<<' '<<len2<<endl;
	ListNode *node1 = head1;
	ListNode *node2 = head2;
	while(node1->next) {
		node1 = node1->next;
	}
	while(node2->next) {
		node2 = node2->next;
	}
	if(node1!=node2) {
		return NULL;
	}
	cout<<"aaaaaa"<<endl;
	node1 = head1;
	node2 = head2;
	if(len1 < len2) {
		node1 = head2;
		node2 = head1;
		int tmp = len1;
		len1 = len2;
		len2 = tmp;
	}
	while(len1 > len2) {
		node1 = node1->next;
		len1--;
	}
	while(node1!=NULL  && node1!=node2) {
		node1 = node1->next;
		node2 = node2->next;
	}
	return node1;
}

ListNode *createList(int *a, int n)
{
	if (!a || n<=0) {
		return NULL;
	}
	ListNode *head = NULL, *tail = NULL;
	for(int i=0;i<n;i++) {
		ListNode *pNode = new ListNode();
		pNode->data = a[i];
		pNode->next = NULL;
		if(NULL == head) {
			head = pNode;
			tail = pNode;
		} else {
			tail->next = pNode;
			tail = pNode;
		}
	}
	return head;
}

void printList(ListNode *head)
{
	if(NULL == head) {
		return;
	}
	while(head) {
		cout<<head->data<<' ';
		head = head->next;
	}
	cout<<endl;
}

int main()
{
	int a[5] = {1,2,3,4,5};
	int b[9] = {9,8,7,6,1,2,3,4,5};
	int c[5] = {1,2,3,4,5};
	ListNode* list1 = createList(a, 5);
	ListNode* list2 = createList(b, 9);
	ListNode* list3 = createList(c, 5);
	if(list1 == list2) {
		cout<<"equal"<<endl;
	} else {
		cout<<"not equal"<<endl;
	}
	printList(list1);
	printList(list2);
	ListNode *list = firstCrossNode(list1, list2);
	printList(list);
}
