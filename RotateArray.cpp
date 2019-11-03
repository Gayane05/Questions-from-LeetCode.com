#include <iostream>
#include <vector>

void rotate(std::vector<int>& nums, int k) 
{
	int size = nums.size();
	std::vector<int> temp_array(k);

	for (int i = 0; i < k; ++i)
	{
		temp_array[i] = nums[size - k + i];

	}
	for (int i = 1; i < size - k + 1 ; ++i)
	{
		nums[size - i] = nums[size - i - k];
	}
	
	std::copy(temp_array.begin(), temp_array.end(), nums.begin());
}

void printArray(std::vector<int>& nums)
{
	for (auto element : nums)
	{
		std::cout << element << " ";
	}
	std::cout << std::endl;
}

int main()
{
	
	std::vector<int> arr = { 1,2,3,4,5,6 };
	
	std::cout << "Before rotation: ";
	printArray(arr);

	int k = -1;
	while (k > arr.size() || k < 0)
	{
		std::cout << "Enter rotation steps, it must be non-negative and less than numbers' count ";
		std::cin >> k;
	}
	
	rotate(arr,k);

	std::cout << "After rotation: ";
	printArray(arr);

	return 0;
}