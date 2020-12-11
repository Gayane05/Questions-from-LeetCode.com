#include <iostream>
#include <vector>

int findMin(std::vector<int>& nums)
{

	// 147 / 147 test cases passed.
	// Runtime : 4 ms
	// Memory Usage : 10.4 MB
	int left = 0;
	int right = nums.size() - 1;

	if (nums.size() == 2)
	{
		if (nums[0] < nums[1])
		{
			return nums[0];
		}
		return nums[1];
	}

	int a = nums[0];
	while (left < right)
	{
		int mid = left + (right - left) / 2;
		if (nums[mid] > nums[mid + 1])
		{
			return nums[mid + 1];
		}
		else if (nums[mid] < nums[mid - 1])
		{
			return nums[mid];
		}
		else
		{
			if (nums[mid] > nums[0])
			{
				left = mid + 1;
			}
			else
			{
				right = mid - 1;
			}
		}
	}

	// Check is necessary for cases like 11, 13, 15, 17 - when rotate count is equal to array size
	if (nums[left] < a)
	{
		return nums[left];
	}
	return a;
}


int main()
{
	//11, 13, 15, 17
	// [3,4,5,1,2]
	std::vector<int> nums{ 11, 13, 15, 17/*4,5,6,7,8,1,2*/ };

	findMin(nums);

	return 0;
}
