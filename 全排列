http://blog.csdn.net/xiazdong/article/details/7986015

#include <iostream>
using namespace std;

void swap(char &a, char &b)
{
	char tmp = a;
	a = b;
	b = tmp;
}
void permutation(char *str, int begin, int end)
{
	if (begin == end) {
		for (int i = 0; i < strlen(str); i++) {
			cout << str[i];
		}
		cout << endl;
		return;
	}
	for (int i = begin; i <= end; i++) { //for循环将begin~end中的每个数放到begin位置中去
		swap(str[begin], str[i]);
		permutation(str, begin + 1, end);
		swap(str[begin], str[i]);
	}
}
int main()
{
	char str[] = "abc";
	permutation(str, 0, 2);
}

abc
acb
bac
bca
cab
cba
