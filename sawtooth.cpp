#include <iostream>
using namespace std;

void partition(int *a, int n) 
{
	if (NULL == a) {
		return;
	}
	int num = a[n-1];
	int i = 0;
	for (int j=i;j<n-1;j++) {
		if(a[j] < num) {
			int tmp = a[i];
			a[i] = a[j];
			a[j] = tmp;
			i++;
		}
