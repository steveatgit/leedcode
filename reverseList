#include<iostream>
using namespace std;

struct List
{
	List *next;
	int data;
};
List *createList(int arr[], int n)
{
	if (n <= 0 || NULL == arr) {
		return NULL;
	}
	List *head = NULL;
	List *tail = NULL;
	for (int i = 0; i < n; i++) {
		List* pNode = new List();
		pNode->next = NULL;
		pNode->data = arr[i];
		if (head == NULL) {
			tail = pNode;
			head = pNode;
		}
		else {
			tail->next = pNode;
			tail = tail->next;
		}
	}
	return head;
}

List *reverseList(List *head)
{
	if (NULL == head) {
		return NULL;
	}
	List *pre = NULL;
	List *curr = head;
	while (curr) {
		List *post = curr->next;
		curr->next = pre;
		pre = curr;
		curr = post;
	}
	return pre;
}
int main()
{
	int arr[5] = { 1, 2, 3, 4, 5 };
	List *head = createList(arr, 5);
	List *reverseHead = reverseList(head);
	while (reverseHead) {
		cout << reverseHead->data << endl;
		reverseHead = reverseHead->next;
	}
	return 0;
}
