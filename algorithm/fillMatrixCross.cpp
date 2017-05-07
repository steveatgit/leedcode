//  斜着填充矩阵，这是一点资讯当时问的题，知道两个for循环的条件，注意下半三角的打印就好，
//  这个程序运行segmentation fault 11,需要调试，注意思路就好

#include<iostream>
using namespace std;

int **fillMatrix(int n)
{
	int **matrix = new int*[n];
	for(int i=0;i<n;i++) {
		matrix[i] = new int[n];
	}
	int value = 1;
	for(int i=0;i<n;i++) {
		for(int j=0;j<=i;j++) {
			matrix[j][i-j] = value++;
		}
	}
	int k=1;
	for(int i=n;i<2*n-1;i++) {
		for(int j=k;j<n;j++) {
			matrix[j][i-j] = value++;
			cout<<matrix[j][i-j]<<endl;
		}
		k++;
	}
	return matrix;
}

void printMatrix(int **matrix, int n)
{
	if(matrix == NULL) {
		return;
	}
	for(int i=0;i<n;i++) {
		for(int j=0;j<n;j++) {
			cout<<matrix[i][j]<<endl;
		}
	}
}

int main()
{
	int n=4;
	int **matrix = fillMatrix(n);
	printMatrix(matrix, n);
	return 1;
}
