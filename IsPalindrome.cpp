#include <iostream>
#include <vector>

bool isPalindrome(int x) 
{
	//// With std::vector<int>.
	//// Runtime 48ms
	//// Memory 9.7MB
	//std::vector<int> numbers;

	//if (x > 0)
	//{
	//	while (x > 0)
	//	{
	//		numbers.push_back(x % 10);
	//		x /= 10;
	//	}
	//}

	//else if (x < 0)
	//{
	//	return false;
	//}

	//else // if number is zero
	//{
	//	return true;
	//}

	//int j = 0;
	//for (int i = 0, j = numbers.size() - 1; i <= numbers.size() / 2; ++i, --j)
	//{
	//	if (numbers[i] != numbers[j])
	//	{
	//		return false;
	//	}
	//}
	//return true;


	// Runtime 8ms
	// Memory 6.3MB
	if (x == 0)
	{
		return true;
	}
	else if (x < 0)
	{
		return false;
	}
	else
	{
		int number = x;
		int digits_count = 0;
		while (number > 0)
		{
			number /= 10;
			digits_count++;
		}

		number = x;
		int count = digits_count;

		while (count > 0)
		{
			int k = number % 10;
			int l = number / pow(10, --count);

			l = l % 10;

			if (k != l)
			{
				return false;
			}
			count--;

			number /= 10;
		}
		return true;
		
	}
}

int main()
{
	isPalindrome(25352);

	return 0;
}
