#include <iostream>

int mySqrt(int x) 
{
	if (x == 0)
	{
		return 0;
	}
	if (x == 1)
	{
		return 1;
	}

	int left = 1;
	int right = x / 2;
	
	int number = 0;
	while (left <= right)
	{
		int mid = left + (right - left) / 2;
		if (mid <= x / mid)
		{
			number = mid;
			left = mid + 1;
		}
		else
		{
			right = mid - 1;
		}
	}
	return number;
}

int main()
{
	mySqrt(4);

	return 0;
}