#include<iostream> 
using namespace std;

char firstNotRepeatingChar(char* arr)
{
	if (NULL == arr) {
		return 0;   // 返回0如果为空
	}
	const int tableSize = 256;
	unsigned int hashTable[tableSize];
	for (int i = 0; i < tableSize; i++) {
		hashTable[i] = 0;
	}
	char *str = arr;
	while (*str != '\0') {
		hashTable[*str++] += 1;
	}
	str = arr;
	while (*str != '\0'){
		if (hashTable[*str] == 1) {
			return *str;
		}
		str++;
	}
	return 0;
}
int main()
{
	char a[20] = "abaccdeff";
	cout << firstNotRepeatingChar(a) << endl;   
	return 0;
}
// b
