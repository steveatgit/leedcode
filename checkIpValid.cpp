#include<iostream>
#include<stdio.h>
using namespace std;

bool checkIPValid(const char* ip)
{
	if(NULL == ip) {
		return false;
	}
	int a=-1, b=-1, c=-1, d=-1;
	char s[100] = {0};
	sscanf(ip, "%d.%d.%d.%d%s", &a, &b, &c, &d, s);
	cout<<a<<' '<<b<<' '<<c<<' '<<d<<' '<<s<<endl;
	if(a>255 || a<0 || b>255 || b<0 || c>255 || c<0 || d>255 || d<0) {
		return false;
	}
	if(s[0] != 0) {
		return false;
	}
	return true;
}

int main()
{
	char ip[100] = "101.12.13.14.15";
	if(checkIPValid(ip)) {
		cout<<"the ip is valid"<<endl;
	} else {
		cout<<"the ip is invalid"<<endl;
	}
	return 1;
}
