#include <stdio.h>

int* twoSum(int *nums, int numSize, int target)
{
	if (nums == NULL || numSize <= 1) {
		return NULL;
	}
	
	int i,j = 0;
	int *arr = (int *)malloc(sizeof(int)*2);
	for (i=0; i<numSize; i++) {
		for (j=1; j<numSize; j++) {
			if (nums[i] + nums[j] == target) {
				arr[0] = i;
				arr[1] = j;
				return arr;
			}
		}
	}
	return NULL;
}

int main()
{
	int nums[4] = {2, 7, 11, 15};
	int *arr = twoSum(nums, 4, 9);
	printf("%d %d", arr[0], arr[1]);
}
