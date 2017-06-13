#include <vector>
#include <iostream>
using namespace std;

vector<vector<int> > subsetsWithDup(vector<int> &S)
{
	vector<vector<int> > res;
	vector<int> emp;
	res.push_back(emp);
	if (S.size() == 0)
		 return res;
	sort(S.begin(), S.end());
	int m = 0;
	for (vector<int>::iterator i=S.begin();i!=S.end();i++) {
		int start = ((i!=S.begin() && *i==*(i-1))?m:0);
		int end = res.size();
		for (int j=start;j<end;j++) {
			vector<int> v;
			for (vector<int>::iterator iter = res[j].begin();iter!=res[j].end();iter++) {
				v.push_back(*iter);
			}
			v.push_back(*i);
			res.push_back(v);
		}
		m = end;
	}
	return res;
}

int main()
{
   vector<int> S;
   for (int i=1;i<3;i++) {
      S.push_back(i);
   }
	S.push_back(2);
   vector<vector<int> > v = subsetsWithDup(S);
   int size = v.size();
   for (int i=0;i<size;i++) {
      for(vector<int>::iterator j = v[i].begin();j!=v[i].end();j++) {
         cout<<*j;
      }
      cout<<endl;
   }
}

	
