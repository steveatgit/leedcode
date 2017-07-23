将奇数放在前面，偶数放在后面

#include <iostream>
using namespace std;

bool isEven(int n)
{
	return (n&1)==0;
}

void recorder(int *a, int n, bool (*func)(int))
{
	if(!a || n<=0) {
		return;
	}
	int *pBegin = a;
	int *pEnd = a+n-1;
	while(pBegin < pEnd) {
		if(!func(*pBegin)) {
			pBegin++;
			continue;
		}
		if(func(*pEnd)) {
			pEnd--;
			continue;
		}
		int tmp = *pBegin;
		*pBegin = *pEnd;
		*pEnd = tmp;
	}
}

void recorderOddEven(int *a, int n)
{
	if(!a|| n<=0) {
		return;
	}
	recorder(a, n, isEven);
}

int main()
{
	int a[6] = {4,2,1,6,3,5};
	recorderOddEven(a, 6);
	for (int i=0;i<6;i++) 
		cout<<a[i]<<' ';  //5 3 1 6 2 4
	cout<<endl;
}
