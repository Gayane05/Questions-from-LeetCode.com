#include <iostream>
#include <vector>
#include <algorithm>

int thirdMax(std::vector<int>& nums) 
{

	// 26 / 26 test cases passed.
	// Runtime : 12 ms
	// Memory Usage : 9.1 MB

	int first_max = 0;

	if (nums.size() < 3)
	{
		for (int i = 1; i < nums.size(); ++i)
		{
			if (nums[i] > nums[first_max])
			{
				first_max = i;
			}
		}
		return nums[first_max];
	}
	else
	{
		std::sort(nums.begin(), nums.end());
		int second_max = 0;
		int third_max = 0;
		int third_max_is_found = false;

		first_max = nums.size() - 1;
		second_max = nums.size() - 2;

		for (int i = nums.size() - 3; i >= 0; --i)
		{
			if (nums[second_max] == nums[first_max])
			{
				second_max--;
			}
			if (nums[i] >= nums[second_max])
			{
				second_max = i;
			}
		}

		third_max = second_max - 1;
		for (int i = second_max - 1; i >= 0; --i)
		{
			if (nums[third_max] == nums[first_max] || nums[third_max] == nums[second_max])
			{
				third_max--;
			}
			if (nums[i] >= nums[third_max] && i != second_max)
			{
				third_max = i;
				third_max_is_found = true;
			}
		}

		if (third_max_is_found)
		{
			return nums[third_max];
		}
		return nums[first_max];
	}
}

int main()
{
	std::vector<int> nums{ 1, 1, 2 };
	thirdMax(nums);

	return 0;
}
