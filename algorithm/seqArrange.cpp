#include <iostream>
using namespace std;

void permutation(char *str, char *begin)
{
	if(!str || !begin) {
		return;
	}
	if(*begin == '\0') {
		cout<<str<<endl;
	} else {
		for(char *pCh = begin;*pCh != '\0';pCh++) {
			char tmp = *pCh;
			*pCh = *begin;
			*begin = tmp;
	
			permutation(str, begin+1);

			tmp = *pCh;
			*pCh = *begin;
			*begin = tmp;
		}
	}
}

int main()
{
	char str[20] = "abc";
	permutation(str, str);
} 
	
		
