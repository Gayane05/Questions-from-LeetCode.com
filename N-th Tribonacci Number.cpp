#include <iostream>

int tribonacci(int n)
{
	// Case 1
	// The Tribonacci sequence Tn is defined as follows: 
	// T0 = 0, T1 = 1, T2 = 1, and Tn + 3 = Tn + Tn + 1 + Tn + 2 for n >= 0.
	// Given n, return the value of Tn.

	// Input: n = 4
	// Output : 4
	// Explanation :
	// T_3 = 0 + 1 + 1 = 2
	// T_4 = 1 + 1 + 2 = 4

	/*if (n == 0)
	{
		return 0;
	}
	if (n == 1 || n == 2)
	{
		return 1;
	}
	if (n == 3)
	{
		return 2;
	}
	else
	{
		return tribonacci(n - 1) + tribonacci(n - 2) + tribonacci(n - 3);
	}
*/

	// Runtime: 0 ms
	// Memory Usage: 6.1 MB
	
	// if (n < 0)
	// {
	// 	return 0;
	// }
	// 
	// // Initialize first three numbers 
	// int first = 0, second = 1;
	// int third = 1;
	// int curr = third;
	// 
	// for (int i = 3; i <= n; ++i)
	// {
	// 	curr = first + second + third;
	// 	first = second;
	// 	second = third;
	// 	third = curr;
	// }
	// return curr;


	// Case 2
	// 0 0 1 1 2 4 7 13 24 44
	// T1 = 0, T2 = 0, T3 = 1, T10 = 44
	/*if (n == 0 || n == 1 || n == 2)
	{
		return 0;
	}
	if (n == 3)
	{
		return 1;
	}
	else
	{
		return tribonacci(n - 1) + tribonacci(n - 2) + tribonacci(n - 3);
	}*/

	
}
int main()
{
	int n = 10;
	tribonacci(4);

	return 0;
}