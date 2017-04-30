#include <stdio.h>
#include <iostream>
using namespace std;

void swap(int &i, int &j)
{
   int temp = i;
   i = j;
   j = temp;
}

int partition(int a[], int p, int r)
{
	int key = a[r - 1];
	int i = p-1;
	for (int j=p; j<r; j++) {
		if(a[j-1] <= key) {
			i++;
			swap(a[i-1], a[j-1]);	
		}
   }
	swap(a[i], a[r-1]);
	return i+1;  //notice
}

int searchMid(int a[], int p, int r, int mid)
{
	int q = partition(a, p, r);
	while (mid != q ) {
		if (q > mid) {
			q = partition(a, p, q-1);
		} else {
			q = partition(a, q+1, r);
		}
	}
	return a[mid-1];
}

int main()
{
	int a[5] = {6,3,4,1,2};
	int mid = (1+5)/2;
	int result = searchMid(a, 1, 5, mid);
	cout<<result<<endl;
}
