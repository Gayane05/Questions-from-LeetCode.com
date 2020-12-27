#include <iostream>
#include <vector>
#include <algorithm> 

int missingNumber(std::vector<int>& nums) 
{
	// 122 / 122 test cases passed.
	// Runtime : 32 ms
	// Memory Usage : 18.3 MB

	int max = 0;
	int sumInArray = 0;

	for (int i = 0; i < nums.size(); ++i)
	{
		if (nums[i] > nums[max])
		{
			max = i;
		}
		sumInArray += nums[i];
	}

	int expectedSum = 0;
	// Gauss' Formula 
	// ∑ i = 0  i = (n(n + 1)) / 2;
	//  n
	expectedSum = (nums.size() * (nums.size() + 1)) / 2;

	// Not Gauss' Formula
	/*
	int k = std::max(nums[max], static_cast<int>(nums.size()));

	for (int i = 1; i <= k; ++i)
	{
		expectedSum += i;
	}*/

	return expectedSum - sumInArray;
}

int main()
{
	std::vector<int> nums{ 0, 1 };

	missingNumber(nums);

	return 0;
}
