#include <iostream>
#include <vector>
#include <numeric>

int pivotIndex(std::vector<int>& nums) 
{
	// Runtime: 44 ms
	// Memory Usage : 31.2 MB

	int Sum = std::accumulate(nums.begin(), nums.end(), 0);

	int LeftSum = 0;
	for(int i = 0; i < nums.size(); ++i)
	{
		if (LeftSum == Sum - nums[i] - LeftSum)
		{
			return i;
		}
		LeftSum += nums[i];
	}
	return -1;
		
}

int main()
{
	std::vector<int> nums{ -1,-1,-1,0,1,-1 };
	pivotIndex(nums);

	return 0;
}
