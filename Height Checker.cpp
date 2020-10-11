#include <iostream>
#include <vector>
#include <algorithm>

int heightChecker(std::vector<int>& heights) 
{
	// 81 / 81 test cases passed.
	// Runtime : 0 ms
	// Memory Usage : 8.5 MB

	std::vector<int> sorted_heights{ heights };
	std::sort(heights.begin(), heights.end());
	
	int count = 0;
	for (int i = 0; i < heights.size(); ++i)
	{
		if (heights[i] != sorted_heights[i])
		{
			count++;
		}
	}

	return count;
}

int main()
{
	std::vector<int> heights{ 1,1,4,2,1,3 };

	heightChecker(heights);
	return 0;
}
