#include <iostream>
using namespace std;

bool findTwoNumWithSum(int a[], size_t length, int sum, int &num1, int &num2)
{
	bool found = false;
	if (length <1 || NULL == a) {
		return found;
	}
	int behind = length-1;
	int ahead = 0;
	int currSum = 0;
	while(ahead<behind) {
		currSum = a[ahead] + a[behind];
		if(currSum == sum) {
			num1 = a[ahead];
			num2 = a[behind];
			found = true;
			break;
		} else if (currSum < sum) {
			ahead++;
		} else {
			behind--;
		}
	}
	return found;
}

int main()
{
	int a[6] = {1,2,4,7,11,15};
	int num1=-1, num2=-1;
	if (findTwoNumWithSum(a, 6, 15, num1, num2)) {
		cout<<num1<<' '<<num2<<endl;
	} else {
		cout<<"not found"<<endl;
	}
}
