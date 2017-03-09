wqu-m01:code wqu$ ./a.out 
true
wqu-m01:code wqu$ cat test.cpp 
#include <iostream>  
using namespace std;  

bool isPostOrder(int arr[], int n)
{
	if(n<=0 || NULL == arr) {
		return false;
	}
	int root = arr[n-1];
	int i = 0;
	for(;i<n-1;i++) {
		if(arr[i] > root) {
			break;
		}
	}
	int j = i;
	for(;j<n-1;j++) {
		if(arr[j] < root) {
			return false;
		}
	}
	bool left=true;
	if(i>0) {
		isPostOrder(arr, i);
	}
	bool right = true;
	if(i<n-1) {
		isPostOrder(arr+i, n-1-i);
	}
	return left&&right;
}
int main()
{
   int a[7] = {5,7,6,9,11,10,8};
   bool ret = isPostOrder(a, 7);
   if(ret) {
      cout<<"true"<<endl;
   } else {
      cout<<"false"<<endl;
   }
}
