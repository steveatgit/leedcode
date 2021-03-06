
#include <iostream>
#include<string>
using namespace std;

void subsetCore(string str, int start, int end, string &s)
{
	if (start == end) {
		cout << s << endl;
		return;
	}
	s += str[start];
	subsetCore(str, start + 1, end, s);
	s = s.substr(0, s.length() - 1);  //. s="abcd"; s.substr(0, s.length()-1) "abc"
	subsetCore(str, start + 1, end, s);
}

void subsetString(string str)
{
	if ("" == str) {  // 注意不能NULL== str
		return;
	}
	int len = str.length();
	string s;
	subsetCore(str, 0, len, s);
}

int main()
{
	string a = "abc";
	subsetString(a);
	cout << endl;
}


abc
ab
ac
a
bc
b
c
