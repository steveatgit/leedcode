#include<iostream>
using namespace std;

int get_key_pos(int *value, int len, int key)
{
	if(value == NULL || len<=0) {
		return -1;
	}
	int low = 0;
	int high = len - 1;
	while(low <= high) {
		int mid = (low + high)/2;
		if(value[mid] == key && value[mid-1]!=key) {
			return mid;
		} else if(value[mid]>=key) {
			high = mid - 1;
		} else {
			low = mid + 1;
		}
	}
}
int main()
{
	int a[6] = {1, 2,3,3,4,5};
	cout<<get_key_pos(a,6,3);
	return 1;
}	
