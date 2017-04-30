#include <stdio.h>

void swap(int &i, int &j)
{
   int temp = i;
   i = j;
   j = temp;
}


void insertSort(int a[], int n)
{
	for (int i=1; i<n; i++) {
		for (int j=i; j>0 & a[j-1] > a[j]; j--) {
			swap(a[j-1], a[j]);
		}
	}
}


int main()
{
	int a[5] = {6,3,4,1,2};
	insertSort(a, 5);
	for(int i=0; i<5; i++) {
		printf("the number is: %d\n", a[i]);
	}
   return 0;
}
