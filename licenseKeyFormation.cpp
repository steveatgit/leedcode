#include <iostream>
#include <vector>
#include <string>
using namespace std;

    string licenseKeyFormatting(string S, int K) {
        if(S=="" || K>12000)
            return "";
        vector<char> vec;
        int strLen = S.length();
        for (int i=0;i<strLen;i++) {
            if (S[i] != '-')
                vec.push_back(S[i]);
        }
        int vecLen = vec.size();
		  cout<<vecLen<<endl;
        int firstLen = vecLen % K;
        cout<<firstLen<<endl;
		  string result = "";
        if (firstLen != 0) {
            for (int i=0;i<firstLen;i++)
                result += vec[i];
            result += '-';
        }
        for (int i=firstLen;i<vecLen;i++) {
            result += vec[i];
            if ((i-firstLen+1)%K == 0 && i!=vecLen-1)
                result += '-';
        }
		  cout<<result<<endl;
        return result;
    }

int main()
{
	string S = "2-4A0r7-4K";
	cout<<licenseKeyFormatting(S, 4);
	cout<<endl;
}
