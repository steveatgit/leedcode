#include <iostream>
using namespace std;

bool isSeqBST(int seq[], int n)
{
	if(NULL==seq || n <=0) {
		return false;
	}
   int	root = seq[n-1];
	int i=0;
	for(;i<n-1;i++) {
		if (seq[i]>root) {
			break;
		}
	}
	int j=i;
	for(;j<n-1;j++) {
		if(seq[j]<root) {
			return false;
		}
	}
	bool left = true;
	if(i>0) {
	   left = isSeqBST(seq, i);
	}
	bool right = true;
	if(i<n-1) {
		right = isSeqBST(seq+i, n-i-1);
	}
	return left&&right;
}
int main()
{
	int a[7] = {5,7,9,6,11,10,8};
	bool ret = isSeqBST(a, 7);
	if(ret) {
		cout<<"true"<<endl;
	} else {
		cout<<"false"<<endl;
	}
}
