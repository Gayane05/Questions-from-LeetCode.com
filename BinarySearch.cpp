#include <iostream>
#include <vector>

int FindElement(std::vector<int>& nums, int val)
{
	if (nums.size() == 0)
	{
		return -1;
	}
	if (nums.size() == 1)
	{
		if (nums[0] == val)
		{
			return 0;
		}
		return - 1;
	}
	if (nums[nums.size() - 1] == val)
	{
		return nums.size() - 1;
	}

	int left = 0;
	int right = nums.size() - 1;
	int mid = 0;

	while (left < right)
	{
		mid = (left + right) / 2;
		if (nums[mid] < val)
		{
			left = mid;
		}
		else if (nums[mid] > val)
		{
			right = mid;
		}
		else
		{
			return mid;
		}
	}
	return -1;
}

int main()
{

	std::vector<int> nums{ 1,2,4,5,8,12,25,46,78,79,102, 156 };
	FindElement(nums, 156);

	return 0;
}