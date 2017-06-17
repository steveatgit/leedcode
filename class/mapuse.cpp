//http://www.cnblogs.com/anywei/archive/2011/10/27/2226830.html
//要求: 将mymap中itemstruct   的a大于100的项删除  
//struct   itemstruct 
//  { 
//            int   a; 
//            char   b[20]; 
//  }; 
//  map<string,   itemstruct   >     mymap. 

#include<iostream>
#include<map>
using namespace std;

typedef struct itemStruct {
	int a;
	char b[20];
}itemS;

itemS s[4] = {{102, "what"},
				  {33, "hello"},
				  {198, "world"},
				  {45, "c++"}};

int main()
{
	map<string, itemS> myMap;
	string str[4] = {"1st", "2nd", "3rd", "4th"};
	for(int i=0;i<4;i++) {
		myMap.insert(make_pair<string, itemS>(str[i], s[i]));
	}
	map<string, itemS>::iterator it;
	for(it = myMap.begin();it!=myMap.end();it++) {
		if(it->second.a > 100) {
			it = myMap.erase(it);
			//myMap.erase(it);  //error, it invalid
		}
	}
	for(it = myMap.begin();it!=myMap.end();it++) {
		cout<<it->first<<" "<<it->second.a<<" "<<it->second.b<<endl;
	}
	return 0;
}
