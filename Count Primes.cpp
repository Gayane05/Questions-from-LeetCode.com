#include <iostream>

int countPrimes(int n) 
{
	// Sieve of Eratosthenes
	// 20 / 20 test cases passed.
	// Runtime : 16 ms
	// Memory Usage : 9 MB

	if (n == 0 || n == 1)
	{
		return 0;
	}
	else if (n == 2)
	{
		return 1;
	}
	else
	{
		bool* isPrime = new bool[n];
		for (int i = 2; i < n; i++) 
		{
			isPrime[i] = true;
		}

		for (int i = 2; i * i < n; i++) 
		{
			if (!isPrime[i])
			{
				continue;
			}
			for (int j = i * i; j < n; j += i) 
			{
				isPrime[j] = false;
			}
		}
		int count = 0;
		for (int i = 2; i < n; i++) {
			if (isPrime[i]) count++;
		}
		delete[] isPrime;
		return count;
	}
}

int main()
{
	countPrimes(30);

	return 0;
}