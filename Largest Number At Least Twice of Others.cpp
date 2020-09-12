#include <iostream>
#include <vector>

int dominantIndex(std::vector<int>& nums) 
{

	// Runtime: 4 ms
	// Memory Usage : 11.3 MB

	int max_index = 0;

	for (int i = 0; i < nums.size(); ++i)
	{
		if (nums[i] > nums[max_index])
		{
			max_index = i;
		}
	}

	for (int i = 0; i < nums.size(); ++i)
	{
		if (i != max_index)
		{
			if (nums[i] != 0)
			{
				if (nums[max_index] < 2 * nums[i])
				{
					return -1;
				}
			}
		}
	}

	return max_index;
}

int main()
{
	std::vector<int> nums{ 0,0,2,1 };
	dominantIndex(nums);

	return 0;
}