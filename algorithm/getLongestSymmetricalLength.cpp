#include<iostream>
using namespace std;

bool isSymmetrical(char *begin, char *end)
{
	if(NULL == begin || NULL == end || begin > end) {
		return false;
	}
	while(begin < end) {
		if(*begin != *end) {
			return false;
		}
		begin++;
		end--;
	}
	return true;
}

/*int getLongestSymmetricalLength_1(char *str)
{
	if(NULL == str) {
		return -1;
	}
	int result = 0;
	int temp = 0;
	int length = strlen(str);
	char *first = str;
   while(first < &str[length-1])	{
		char *last = first + 1;
		while(last <= &str[length-1]) {
			if(isSymmetrical(first, last)) {
				temp = last - first + 1;
				if (temp > result) {
					result = temp;
				}
			} 
			last++;
		}
		first++;
	}
	return result;
}*/

int getLongestSymmetricalLength(char *str)
{
	if(NULL == str) {
		return -1;
	}
	int result = 0;
	char *pStr = str;
	int temp = 0;
	while (*pStr != '\0') {
		//  odd number char
		char *left = pStr-1;
		char *right = pStr+1;
		while(left>=str && *right!='\0' && *left==*right) {
			left--;
			right++;
		}
		temp = right - left -1;
		if (temp > result) {
			result = temp;	
		}
		
		// even number char 
		left = pStr;
		right = pStr+1;
		while(left>=str && *right!='\0' && *left==*right) {
			left--;
			right++;
		}
		temp = right - left -1;
		if (temp > result) {
			result = temp;	
		}
		pStr++;
	}
	return result;
}
				
int main()
{
	char str[10] = "google";
	cout<<getLongestSymmetricalLength(str)<<endl;
	return 0;
}
