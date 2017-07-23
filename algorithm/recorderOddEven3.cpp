奇数在前，偶数在后，保持原始数据的位置不变
思路还是快排的partition，但是在交换的时候，需要把i到j的数据向后依次后移，然后把
arr[j]放在arr[i]的位置。

#include <iostream>
using namespace std;

void swap(int &a, int &b)
{
	int tmp = a;
	a = b;
	b = tmp;
}
void partition(int arr[], int n)
{
	if (n <= 0 || NULL == arr) {
		return;
	}
	int i = 0;
	int j = 0;
	for (; j < n; j++) {
		if (arr[j] % 2 == 1) {
			int tmp = arr[j];
			for(int k = j-1;k>=i;k--) {
				arr[k+1] = arr[k];
			}
			arr[i] = tmp;
			i++;
		}
	}
}
int main()
{
	int a[6] = { 4, 2, 1, 6, 3, 5 };
	partition(a, 6);
	for (int i = 0; i<6; i++)
		cout << a[i] << ' ';
	cout << endl;
}
// 1 3 5 4 2 6
