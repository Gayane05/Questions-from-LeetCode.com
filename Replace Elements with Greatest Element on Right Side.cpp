#include <iostream>
#include <vector>

std::vector<int> replaceElements(std::vector<int>& arr) 
{
	// 15 / 15 test cases passed.
	// Runtime : 20 ms
	// Memory Usage : 15 MB

	int size = arr.size();
	int temp = 0;
	int max = arr[size - 1];

	for (int i = size - 2; i >= 0; --i)
	{
			temp = arr[i];
			arr[i] = max;
			if (max <= temp)
			{
				max = temp;
			}		
	}
	arr[size - 1] = -1;
	return arr;
}

int main()
{
	std::vector<int> nums{ 17,18,5,4,6,1 };
	replaceElements(nums);

	return 0;
}