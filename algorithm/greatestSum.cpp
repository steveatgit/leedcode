#include<iostream>
using namespace std;

void greatestSum(int a[], int n)
{
	if (n <= 0 || NULL == a) {
		return;
	}
	int biggest = -10000;
	int tempResult = 0, result = 0;
	int begin = 0, end = 0;
	for (int i = 0; i<n; i++) {
		if (tempResult <= 0) {
			tempResult = a[i];
			begin = i;
		}
		else {
			tempResult += a[i];
		}
		if (tempResult > result) {
			result = tempResult;
			end = i;
		}
		if (biggest < a[i]) {
			biggest = a[i];
		}
	}
	if (biggest < 0) {
		cout << biggest << endl;
	}
	else {
		cout << result << endl;
		for (int i = begin; i <= end; i++) {
			cout << a[i] << endl;
		}
	}
}

int main()
{
	int a[8] = { 1 - 2, 3, 10, -4, 7, 2, -5 };
	greatestSum(a, 8);
}
// 18
// 3 10 -4 7 2
