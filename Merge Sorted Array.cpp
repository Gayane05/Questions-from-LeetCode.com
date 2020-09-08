#include <iostream>
#include <vector>

void merge(std::vector<int>& nums1, int m, std::vector<int>& nums2, int n) 
{
	// 59 / 59 test cases passed.
	// Runtime: 4 ms
	// Memory Usage : 9.1 MB

	if (n == 0)
	{
		return;
	}
	if (nums1.size() >= m + n)
	{

		std::vector<int>::iterator it_1 = nums1.begin();

		int i = 0;
		int j = 0;
		int count = 0;
		while (j < nums2.size())
		{
			if (nums1[i] > nums2[j])
			{
				it_1 = nums1.insert(nums1.begin() + i, nums2[j]);
				count++;
				++j;
			}
			else if ( i < m + count)
			{
				++i;
			}
			else
			{
				nums1.insert(nums1.begin() + i, nums2[j]);
				++i;
				++j;
				it_1 = nums1.begin() + i;
			}
		}
		it_1 = std::find(it_1, nums1.end(), 0);
		if (it_1 < nums1.begin() + m + n)
		{
			it_1++;
		}
		nums1.erase(it_1, nums1.end());
	}
}

int main()
{

	std::vector<int> nums1{ 1,2,3,0,0,0 };
	std::vector<int> nums2{ 2,5,6 };

	merge(nums1, 3, nums2, 3);

	return 0;
}
