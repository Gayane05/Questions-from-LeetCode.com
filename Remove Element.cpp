#include <iostream>
#include <vector>

int removeElement(std::vector<int>& nums, int val) 
{
	// 
	/*113 / 113 test cases passed.
	Runtime : 4 ms
	Memory Usage : 9.1 MB*/

	int i = 0;
	for (int j = 0; j < nums.size(); j++) 
	{
		if (nums[j] != val) 
		{
			nums[i] = nums[j];
			i++;
		}
	}
	return i;
}
// //
//int removeElement(vector<int>& nums, int val) {
//	return std::distance(nums.begin(), std::remove(nums.begin(), nums.end(), val));
//}
int main()
{
	std::vector<int> nums{ 0,4,4,0,4,4,4,0,2 };

	removeElement(nums, 4);

	return 0;
}