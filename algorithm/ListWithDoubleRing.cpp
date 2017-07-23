//http://blog.csdn.net/qq_32953481/article/details/50410138
#include<iostream>
using namespace std;

struct List{
List *next;
List *pre;
int data;
};

List *add(List *head, int data)
{
	if(head == NULL) {
		List *head = new List();
		head->data = data;
		head->next = head;
		head->pre = head;
		return head;
	}
	List *pre = head->pre;
	List *cur = head;
	List *pNode = new List();
	pNode->data = data;
	pNode->pre = pre;
	pNode->next = cur;
	pre->next = pNode;
	cur->pre = pNode;
	head = pNode;
	return head;
}

void print(List *head)
{
	if(NULL == head) {
		return;
	}
	List *pre = head->pre;
	pre->next = NULL;
	List *cur = head;
	while(cur) {
		cout<<cur->data<<endl;
		cur = cur->next;
	}
}

int main()
{
	int n = 4;
	List *head = NULL;
	for (int i=1;i<=n;i++) {
		head = add(head, i);
	}
	print(head);
	return 1;
}

	
