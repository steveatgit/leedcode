#include <iostream>
#include <deque>
using namespace std;

void mergeCrossSet(deque<long> &deque1)
{
	deque<long>::iterator iter = deque1.begin();
	long first = *iter;
	for(iter++;iter!=deque1.end();iter++) {
		if(first & *iter) {
			first = first | *iter;
			iter = deque1.erase(iter);
		}
	}
	cout<<hex<<deque1.front()<<' ';
	deque1.pop_front();
	if (deque1.size()) {
		mergeCrossSet(deque1);	
	}
}
		
int main()
{
	// long a = [11100000, 01010000, 00001100, 00000010, 00010001];
	long a[5] = {0xe0, 0x50, 0x0c, 0x02, 0x11};
	deque<long> deque1;
	for(int i=0;i<5;i++) {
		deque1.push_back(a[i]);
	}
	deque<long>::iterator iter = deque1.begin();
	for(;iter!=deque1.end();iter++) {
		cout<<hex<<*iter<<' ';
	}
	mergeCrossSet(deque1);
}
	
