#include <iostream>
using namespace std;

void printSeq(int small, int big)
{
	for (int i=small;i<=big;i++) {
		cout<<i<<' ';
	}	
	cout<<endl;
}
void getSequence(int n)
{
	if(n<3) {
		return;
	}
	int small = 1;
	int big = 2;
	int sum = small + big;
	int middle = (n+1)/2;
	while(small < middle) {
		if(sum == n) {
			printSeq(small, big);
		}
		while(sum>n) {
			sum -= small;
			small++;
			if(sum == n) {
				printSeq(small, big);
			}
		}
		big++;
		sum += big;
	}
}


int main()
{
	int n = 15;
	getSequence(n);
}
