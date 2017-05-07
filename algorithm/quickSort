#include<iostream>
using namespace std;

void swap(int &a, int &b)
{
	int tmp = a;
	a = b;
	b = tmp;
}
int partition(int arr[], int p, int r)
{
	int k = arr[r];
	int i = p - 1;
	for (int j = p; j < r; j++) {
		if (arr[j] < k) {
			i++;
			swap(arr[i], arr[j]);
		}
	}
	swap(arr[++i], arr[r]);
	return i;
}
void quickSort(int arr[], int p, int r)
{
	if (arr == NULL) {
		return;
	}
	if (p < r) {
		int q = partition(arr, p, r);
		quickSort(arr, p, q-1); //  notice q-1, or dead cycle
		quickSort(arr, q + 1, r);
	}
}
int main()
{
	int arr[5] = { 3, 2, 1, 5, 4 };
	quickSort(arr, 0, 4);
	for (int i = 0; i < 5; i++) {
		cout << arr[i] << endl;
	}
}
