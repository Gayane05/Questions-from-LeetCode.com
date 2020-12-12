#include <iostream>
// Fibonacci Number

int fib(int N) 
{
	// Recursive way
	// Status: Accepted
	// Runtime : 20 ms
	// Memory Usage : 6.3 MB
	if (N == 0)
	{
		return 0;
	}
	if (N == 1)
	{
		return 1;
	}
	else return (fib(N - 1) + fib(N - 2));
}

int main()
{
	fib(4);
	return 0;
}
