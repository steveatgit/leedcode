#include <iostream>
#include <vector>
using namespace std;

vector<vector<int> > res;


void subsetsCore(vector<int> &S, int start, vector<int>&v)
{
	if(start == S.size()) {
		res.push_back(v);
		return;
	}
	vector<int> v2;
/*	for (vector<int>::iterator iter = v.begin();iter!=v.end();iter++) {
		v2.push_back(*iter);
	}*/
	
	v.push_back(S[start]);
	subsetsCore(S, start+1, v);
	v.pop_back();
	subsetsCore(S, start+1, v);
}

vector<vector<int> > subsets(vector<int> &S)
{
	vector<int> v;
	sort(S.begin(), S.end());
	subsetsCore(S, 0, v);
	return res;
}

int main()
{
	vector<int> S;
	for (int i=1;i<4;i++) {
		S.push_back(i);
	}
	subsets(S);
	for (int i=0;i<res.size();i++) {
		for (vector<int>::iterator iter = res[i].begin();iter!=res[i].end();iter++) {
			cout<<*iter;
		}
		cout<<endl;
	}
}
