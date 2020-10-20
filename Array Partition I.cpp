#include <iostream>
#include <vector>
#include <algorithm>

int arrayPairSum(std::vector<int>& nums) 
{

	// 81 / 81 test cases passed.
	// Runtime : 132 ms
	// Memory Usage : 28.4 MB
	if (nums.size() == 1)
	{
		return nums[0];
	}
	if (nums.size() == 2)
	{
		return std::min(nums[0], nums[1]);
	}
	
	sort(nums.begin(), nums.end());
	int sum = 0;
	int i = 0;
	while (i < nums.size() - 1)
	{
		sum += (std::min(nums[i], nums[i + 1]));
		i = i + 2;
	}

	return sum;
}

int main()
{
	std::vector<int> nums{ 9,1,5,6,7,2 };
	arrayPairSum(nums);

	return 0;
}
