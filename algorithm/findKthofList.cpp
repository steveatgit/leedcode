#include <iostream>
using namespace std;

struct ListNode
{
	int data;
	ListNode *next;
	ListNode(int x): data(x), next(NULL) {}
};

ListNode* createList(int *arr, int n)
{
	if(NULL == arr || n<=0) {
		return NULL;
	}
	ListNode *head = NULL, *tail = NULL;
	for (int i=0;i<n;i++) {
		ListNode *pNode = new ListNode(0);
		pNode->data = arr[i];
		pNode->next = NULL;
		if (head == NULL) {
			tail = pNode;
			head = pNode;
		} else {
			tail->next = pNode;
			tail = pNode;
		}
	}
	return head;
}
void printList(ListNode *head)
{
	while(head != NULL) {
		cout<<head->data<<' ';
		head = head->next;
	}
	cout<<endl;
}
ListNode* findKthofList(ListNode* head, unsigned int k)
{
	ListNode *ahead = head, *behind = head;
	for (int i=0;i<k;i++) {
		if(behind->next != NULL) {
			behind = behind->next;
		} else {
			return NULL;
		}
	}
	while(behind != NULL) {
		ahead = ahead->next;
		behind = behind->next;
	}
	return ahead;
}

int main()	
{
	int a[5] = {4,2,5,1,3};
	ListNode *head = createList(a, 5);
	ListNode *node = findKthofList(head, 3);
	printList(node);
}
