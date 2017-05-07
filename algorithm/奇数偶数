
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
			swap(arr[i], arr[j]);
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
// 1 3 5 6 2 4
