#include <iostream>
#include <vector>

int findNumbers(std::vector<int>& nums) 
{
	// Runtime: 12 ms
	// Memory Usage : 10 MB
	int number_count = 0;
	int digit_count = 0;
	for (int i = 0; i < nums.size(); ++i)
	{
		digit_count = 0;
		int n = nums[i];
		while (n > 0)
		{
			n /= 10;
			digit_count++;
		}
		if (digit_count % 2 == 0)
		{
			number_count++;
		}
	}
	return number_count;
}

int main()
{
	std::vector<int> nums{ 12,345,2,6,7896 };
	findNumbers(nums);

	return 0;
}
