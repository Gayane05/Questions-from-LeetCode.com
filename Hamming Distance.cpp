#include <iostream>

void countOnesInNumber(int number, int& count)
{
	if (number == 1)
	{
		return;
	}
	else
	{
		if (number % 2 != 0)
		{
			count++;
		}
		number /= 2;
		countOnesInNumber(number, count);
	}
	
}

// Runtime: 0 ms,
// Memory Usage: 6.5 MB
int hammingDistance(int x, int y) 
{
	if (x == 0 && y == 0)
	{
		return 0;
	}

	int number = x ^ y;
	if (number == 0)
	{
		return 0;
	}
	int onesCount = 0;
	countOnesInNumber(number, onesCount);

	return ++onesCount;
}

int main()
{
    
	hammingDistance(8, 8);
	return 0;
}