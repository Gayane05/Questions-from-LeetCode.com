#include <iostream>
#include <vector>

bool isOdd(int number)
{
	if (number % 2 != 0)
	{
		return true;
	}
	return false;
}

std::vector<int> sortArrayByParity(std::vector<int>& A) 
{
	// 285 / 285 test cases passed.
	//	Runtime : 12 ms
	//	Memory Usage : 16.4 MB
	//int i = 0;
	//int j = 0;

	while (i < A.size() && j < A.size())
	{
		if (!isOdd(A[i]))
		{
			++i;
		}
		if (!isOdd(A[j]))
		{
			if (i < j)
			{
				std::swap(A[i], A[j]);
				++i;
			}
			else
			{
				++j;
			}
		}
		else
		{
			++j;
		}
	}
	return A;

	// Not my solution - but a good one.
	/*int left = 0;
	for (int i = 0; i < A.size(); i++) 
	{
		if (A[i] % 2 == 0) 
		{
			if (i != left)
				std::swap(A[i], A[left]);
			left++;
		}
	}

	return A;*/


	// After every even number will be one odd number - 2,3,4,1
	/*while(i < A.size() && j < A.size())
	{
		if (!isOdd(A[i]))
		{
			++i;
		}
		if (!isOdd(A[j]))
		{
			if (i < j)
			{
				std::swap(A[i], A[j]);
				i = j;
			}
		}
		else
		{
			++j;
		}
	}
	return A;*/
}

int main()
{
	std::vector<int> nums{ 3,4,2,1 };

	sortArrayByParity(nums);

	return 0;
}
