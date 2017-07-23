#include<iostream>
#include<vector>
using namespace std;

#define VALUE 20

int replaceMin(vector<int> &vec)
{
	vector<int> minP;
	int min = INT_MAX;
	for(int i=0;i<vec.size();i++) {
		if(vec[i] < min) {
			min = vec[i];
		}
	}
	for(int i=0;i<vec.size();i++) {
		if(vec[i] == min) {
			vec[i] = VALUE;
		}
	}
	return min;
}

int main()
{
	int arr[5] = {2,1,1,4,5};
	vector<int> vec;
	for(int i=0;i<5;i++) {
		vec.push_back(arr[i]);
	}
	cout<<replaceMin(vec)<<endl;
	for(int i=0;i<vec.size();i++) {
		cout<<vec[i]<<endl;
	}
	return 1;
}
