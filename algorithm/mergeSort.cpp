#include<iostream>
using namespace std;

void merge(int arr[], int p, int q, int r)
{
	int left = q - p + 1;
	int right = r - q;
	int *arr_left = new int[left + 1];
	int *arr_right = new int[right + 1];
	for (int i = 0; i < left; i++) {
		arr_left[i] = arr[i+p];
	}
	arr_left[left] = INT_MAX;
	for (int i = 0; i < right; i++) {
		arr_right[i] = arr[i+q+1];
	}
	arr_right[right] = INT_MAX;
	int i = 0, j = 0;
	for (int k = p; k <= r;k++) {
		if (arr_left[i] < arr_right[j]) {
			arr[k] = arr_left[i];
			i++;
		}
		else {
			arr[k] = arr_right[j];
			j++;
		}
	}
	delete[] arr_left;
	delete[] arr_right;
	arr_left = NULL;
	arr_right = NULL;
}
void mergeSort(int arr[], int p, int r)
{
	if (p < r) {
		int q = (p + r) >> 1;
		mergeSort(arr, p, q); // 这里是0,2，是三个数据，所以在merge中left要+1
		mergeSort(arr, q + 1, r);
		merge(arr, p, q, r);
	}
}
int main()
{
	int arr[5] = { 3, 2, 1, 5, 4 };
	mergeSort(arr, 0, 4);
	for (int i = 0; i < 5; i++) {
		cout << arr[i] << endl;
	}
}
