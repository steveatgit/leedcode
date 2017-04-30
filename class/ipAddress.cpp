#include<iostream>
#include<stdio.h>
#include<string.h>

bool checkPoint(char *str)
{
	int npoint = 0;
	while(*str) {
		*str == '.' ? npoint++ : npoint;
		if(!(*str == '.') && !((*str < '9') && (*str >'0'))) {
			return false;
		}
	}
	return npoint == 3;
}

bool checkInRange(int addr[4])
{
	for (int i = 0; i<4; i++) {
		if(addr[i]<1 || addr[i]>255) {
			return false;
		}
	}
	return true;
}

bool convertIp(char s[], int addr[4])
{
	char tmp[128];
	if (checkPoint(s)) {
		sscanf(s, "%d.%d.%d.%d", addr[0], addr[1], addr[2], addr[3]);
		sprintf_s(tmp, sizeof(tmp), "%d.%d.%d.%d", addr[0], addr[1], addr[2], addr[3]);
		if (strcmp(tmp, s) == 0 && checkInRange(addr)) {
			return true;
		}
	}
	return false;
}

int main()
{
	char s[128];
	int addr[4];
	while(scanf("%s", s) != EOF) {
		if (convertIp(s, addr)) {
			int result = 0;
			result += addr[0] * (1<<24);
			result += addr[1] * (1<<16);
			result += addr[2] * (1<<8);
			result += addr[3];
			return result;
		}
	}
	return -1;
}

