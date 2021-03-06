wqu-m01:code wqu$ ./a.out 
4 3 2 1 
O(n+nlogk)
wqu-m01:code wqu$ cat test.cpp 
#include <iostream>  
#include <vector>  
#include <set>
using namespace std;  

void getLeastK(vector<int> data, multiset<int, greater<int> >&leastNum, int size)
{
	if(size<1 || data.size()<size) {
		return;
	}
	for(vector<int>::iterator iter = data.begin();iter!=data.end();iter++) {
		if(leastNum.size()<size) {
			leastNum.insert(*iter);
		} else {
			multiset<int, greater<int> >::iterator iterK = leastNum.begin();
			if(*iterK > *iter) {
				leastNum.erase(*iterK);
				leastNum.insert(*iter);
			}
		}
	}
}
void printLeastK(multiset<int, greater<int> > &leastNum)
{
	for(multiset<int, greater<int> >::iterator iter=leastNum.begin();iter!=leastNum.end();iter++) {
		cout<<*iter<<" ";
	}
	cout<<endl;
}
int main()
{
   int a[6] = {6,3,2,1,7,4};
   vector<int> data;
   for (int i=0;i<6;i++) {
      data.push_back(a[i]);
   }
   multiset<int, greater<int> > leastNum;
   getLeastK(data, leastNum, 4);
   printLeastK(leastNum);
} 
