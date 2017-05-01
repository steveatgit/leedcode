#include <iostream>
using namespace std;

void reverse(char *begin, char *end)
{
	while(begin < end) {
		char tmp = *begin;
		*begin = *end;
		*end = tmp;
		begin++;
		end--;
	}
	return;
}

void reverseSen(char *sen)
{
	char *begin = sen;
	char *end = sen;
	while(*end != '\0') {
		end++;
	}
	reverse(begin, --end);
	end = sen;
	while(*begin != '\0') {
		if(*begin == ' ') {
			begin++;
			end++;
		} else		if(*end == ' ' || *end == '\0') {
			reverse(begin, --end);
			begin = ++end;
		} else {
			end++;
		}
	}
	return;
}

int main()
{
	char sen[20] = "this is a sen.";
	reverseSen(sen);
	cout<<sen<<endl;
}
	
