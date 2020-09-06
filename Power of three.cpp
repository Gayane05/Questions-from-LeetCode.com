#include <iostream>

bool isPowerOfThree(int n) 
{

	// Runtime: 12 ms
	// Memory Usage : 6 MB
	if (n < 0 || n == 0)
	{
		return false;
	}

	while (n % 3 == 0)
	{
		n /= 3;
	}

	return n == 1;
}

int main()
{
	isPowerOfThree(27);

	return 0;
}