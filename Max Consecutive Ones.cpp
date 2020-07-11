#include <iostream>
#include <vector>
#include <algorithm>

int findMaxConsecutiveOnes(std::vector<int>& nums)
{
	// Runtime: 140 ms
	// Memory Usage : 36.2 MB
	/*int max = 0;
	int count = 0;
	for (int i = 0; i < nums.size(); ++i)
	{
		count = 0;
		while (nums[i] == 1 && i < nums.size())
		{
			count++;
			++i;
		}
		if (count > max)
		{
			max = count;
		}
	}
	return max;*/

	// Runtime: 84/88/92 ms
	// Memory Usage : 36.3/36.4 MB
	int max = 0;
	int count = 0;
	for (int i = 0; i < nums.size(); ++i)
	{
		if (nums[i] == 1)
		{
			++count;
		}
		else
		{
			count = 0;
		}
		max = std::max(count, max);
	}
	return max;

}

int main()
{
	std::vector<int> v{ 0, 1 };
	findMaxConsecutiveOnes(v);

	return 0;
}