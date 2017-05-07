#include <iostream>
using namespace std;

struct List{
	List *next;
	int data;
	List(int m_data):data(m_data), next(NULL){}  // notice the write style, only constructor(构造函数) can be initialized
};

List *createList(int arr[], int n)
{
	List *head = NULL, *tail = NULL;
	List *pList = new List(arr[0]);
	head = pList;
	tail = pList;
	for(int i=1;i<n;i++) {
		pList = new List(arr[i]);
		tail->next = pList;
		tail = pList;
	}
	return head;
}

void printList(List *head)
{
	if(NULL == head) {
		return;
	}
	while(head!=NULL) {
		cout<<head->data<<endl;
		head = head->next;
	}
}

int main()
{
	int arr[5] = {3,2,1,4,5};
	List *head = createList(arr, 5);
	printList(head);
	return 0;
}

