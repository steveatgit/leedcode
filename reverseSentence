//反转句子“I am a student.”   "student. a am I"
#include<iostream>
using namespace std;

void reverse(char *begin, char *end)
{
	if (NULL == begin || NULL == end || begin >= end) {
		return;
	}
	while (begin < end) {
		int tmp = *begin;
		*begin = *end;
		*end = tmp;
		begin++;
		end--;
	}
}
void reverseSentence(char *sentence)
{
	if (NULL == sentence) {
		return;
	}
	char *begin = sentence;
	char *end = sentence;
	while (*end != '\0') {
		end++;
	}
	reverse(begin, --end);
	begin = end = sentence;
	while (*begin != '\0') {
		if (*begin == ' ') {
			begin++;
			end++;
		}
		else if (*end == ' ' || *end == '\0') {
			reverse(begin, --end);
			begin = ++end;
		}
		else {
			++end;
		}
	}
}
int main()
{
	char str[30] = "I am a student.";
	reverseSentence(str);
	cout << str << endl;
}
