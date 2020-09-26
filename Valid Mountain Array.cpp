#include <iostream>
#include <vector>

bool validMountainArray(std::vector<int>& A) 
{

	// 51 / 51 test cases passed.
	// Runtime : 52 ms
	// Memory Usage : 22.6 MB
	if (A.size() == 1)
	{
		return false;
	}

	int max = 0;
	int i = 0;
	bool beforePoint = false;
	bool afterPoint = false;

	while (i < A.size() && i + 1 < A.size())
	{
		if (A[i] == A[i + 1])
		{
			return false;
		}
		if (A[i] > A[i + 1])
		{
			break;
		}
		else
		{
			++i;
			beforePoint = true;
		}	
	}

	if (beforePoint == false)
	{
		return false;
	}

	max = i;

	while (++i < A.size() && max < A.size())
	{
		if (A[max] > A[i])
		{
			max++;
			afterPoint = true;
		}
		else
		{
			return false;
		}
	}

	if (afterPoint == false)
	{
		return false;
	}
	return true;
}

int main()
{
	std::vector<int> nums{ 0,1,2,3,4,5,6,7,8,9 };
	validMountainArray(nums);

	return 0;
}
