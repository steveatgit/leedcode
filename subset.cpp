#include <vector>
#include <iostream>
using namespace std;

vector<vector<int> > subsets(vector<int> &S)
{
  	vector<vector<int> > res;
	vector<int> emp;
   res.push_back(emp);
	if (S.size() == 0) 
		return res;
	sort(S.begin(), S.end());
	for (vector<int>::iterator iter = S.begin();iter!=S.end();iter++) {
		int size = res.size();
		for (int i=0;i<size;i++) {
			vector<int> vec;
			for (vector<int>::iterator j = res[i].begin();j!=res[i].end();j++) {
				vec.push_back(*j);
			}
			vec.push_back(*iter);
			res.push_back(vec);
		}
	}
	return res;
}

int main()
{
	vector<int> S;
	for (int i=1;i<=3;i++) {
		S.push_back(i);
	}
	vector<vector<int> > v = subsets(S);
	int size = v.size();
	for (int i=0;i<size;i++) {
		for(vector<int>::iterator j = v[i].begin();j!=v[i].end();j++) {
			cout<<*j;
		}
		cout<<endl;
	}
}
