#include <iostream>
#include <vector>

// NBYM
int search(std::vector<int>& nums, int left, int right)
{
	// Status: Accepted
	// Runtime : 4 ms
	// Memory Usage : 9.2 MB
	if (left < right)
	{
		int mid = left + (right - left) / 2;
		if (nums[mid] > nums[mid + 1])
		{
			//left = mid;
			search(nums, left, mid);
		}
		else
		{
			//left = mid + 1;
			search(nums, mid + 1, right);
		}
	}
}

int findPeakElement(std::vector<int>& nums) 
{
	return search(nums, 0, nums.size());
}


int main()
{
	std::vector<int> nums{ 1,1,1,3,5,6,4 };

	findPeakElement(nums);

	return 0;
}
