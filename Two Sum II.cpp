#include <iostream>
#include <vector>

std::vector<int> twoSum(std::vector<int>& numbers, int target) 
{
	// 17 / 17 test cases passed.
	// Runtime: 8 ms
	// Memory Usage: 10 MB

	std::vector<int> result;
	if (numbers.size() == 2)
	{
		if (numbers[0] + numbers[1] == target)
		{
			result.push_back(1);
			result.push_back(2);
		}
	}
	else
	{
		int n = numbers.size();
		int i = 0;
		int number = 0;
		int left = i + 1;
		int right = n - 1;

		for (int i = 0; i < n; ++i)
		{
			number = target - numbers[i];
			left = i + 1;
			right = n - 1;
			while (left <= right)
			{
				int mid = (left + right) / 2;
				if (numbers[mid] == number)
				{
					result.push_back(i + 1);
					result.push_back(mid + 1);
					return result;
				}
				else if (numbers[mid] > number)
				{
					right = mid - 1;
				}
				else
				{
					left = mid + 1;
				}
			}
		}
	}
	return result;

	
}

int main()
{

	std::vector<int> nums{ 5,25,75 };
	twoSum(nums, 100);

	return 0;
}
