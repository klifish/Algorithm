#include "sort.h"

//
void InsertionSort(vector<int>& nums)
{
	int size = nums.size();
	for (int j = 1; j < size; j++) {
		int key = nums[j];
		int i = j - 1;
		while (i > -1 && nums[i] > key) {
			nums[i + 1] = nums[i];
			i--;
		}
		nums[i + 1] = key;
	}
}
