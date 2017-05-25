#include<iostream>
using namespace std;

void swap(int &a, int &b)
{
	int tmp = a;
	a = b;
	b = tmp;
}
void maxHepify(int arr[], int n, int size)
{
	int left = 2 * n;
	int right = 2 * n + 1;
	int maxIndex = n;
	if (left <= size && arr[left - 1] > arr[maxIndex - 1]) {
		maxIndex = left;
	}
	if (right <= size && arr[right - 1] > arr[maxIndex - 1]) {
		maxIndex = right;
	}
	if (maxIndex != n) {
		swap(arr[maxIndex - 1], arr[n - 1]);
		maxHepify(arr, maxIndex, size);  // 递归	
}
}
void buildHepify(int arr[], int size) {
	for (int i = size / 2; i > 0; i--) {
		maxHepify(arr, i, size);
	}
}
void hepifySort(int arr[], int size) {
	buildHepify(arr, size);
	for (int i = size; i > 0; i--) {
		swap(arr[0], arr[i - 1]);
		maxHepify(arr, 1, i - 1);   // size 逐渐减1	
  }
}
int main()
{
	int arr[5] = { 3, 2, 1, 5, 4 };
	hepifySort(arr, 5);
	for (int i = 0; i < 5; i++) {
		cout << arr[i] << endl;
	}
}
