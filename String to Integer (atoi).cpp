#include <iostream>
#include <set>
#include <string>
#include <vector>
#include <limits>       // std::numeric_limits

int myAtoi(std::string str) 
{

	// Example 1 :
	// Input: "42"
	// Output : 42

	// Example 2 :
	// Input : "   -42"
	// Output : -42
	// Explanation : The first non - whitespace character is '-', which is the minus sign.
	// Then take as many numerical digits as possible, which gets 42.
	
	// Example 3 :
	// Input : "4193 with words"
	// Output : 4193
	// Explanation : Conversion stops at digit '3' as the next character is not a numerical digit.
	
	// Example 4 :
	// Input : "words and 987"
	// Output : 0
	// Explanation : The first non - whitespace character is 'w', which is not a numerical
	// digit or a + / -sign.Therefore no valid conversion could be performed.
	
	// Example 5 :
	// Input : "-91283472332"
	// Output : -2147483648
	// Explanation : The number "-91283472332" is out of the range of a 32 - bit signed integer.
	// Thefore INT_MIN(−231) is returned.

	// Example 6 :
	// Input : "0-1"
	// Output : 0

	// Example 7 :
	// Input : "-0000022"
	// Output : 22

	// Example 8:
	// Input : "+78"
	// Output : 78

	// 1079 / 1079 test cases passed.
	// With using additional memory: std::vector<int>
	//	Runtime : 4 ms
	//	Memory Usage : 6.7 MB

	int i = 0;
	if (str[i] == '0' && !isdigit(str[i + 1])) // 0-1
	{
		return 0;
	}	

	while (str[i] == ' ' || str[i] == '0')
	{
		++i;
	}

	if (str[i] == '-' || isdigit(str[i]) || str[i] == '+')
	{
		long long number = 0;
		std::vector<int> myvector;
		char sign = '+';

		if (str[i] == '-')
		{
			sign = '-';
			++i;
		}
		else if (str[i] == '+')
		{
			++i;
		}

		while (str[i] == '0')
		{
			++i;
		}


		while (isdigit(str[i]))
		{
			myvector.push_back(str[i] - 48);
			++i;
		}

		if (myvector.size() > 0)
		{
			int l = myvector.size() - 1;
			int j = 0;
			int digits_count = 0;
			bool isBig = false;

			while (l >= 0)
			{
				if (digits_count == 11)
				{
					isBig = true;
					break;
				}
				number = (myvector[l] * pow(10, j)) + number;
				++j;
				--l;
				digits_count++;
			}

			if (sign == '-')
			{
				number *= -1;
			}

			if (isBig && sign == '+')
			{
				return INT_MAX;
			}
			else if (isBig && sign == '-')
			{
				return INT_MIN;
			}
			if (number > INT_MAX)
			{
				return INT_MAX;
			}
			else if (number < INT_MIN)
			{
				return INT_MIN;
			}

			return number;
		}
		else return 0;
	}
	else
	{
		return 0;
	}

	// Without using additional memory
	// Runtime: 4 ms
	// Memory Usage : 6.4 MB

	int i = 0;
	if (str[i] == '0' && !isdigit(str[i + 1])) // 0-1
	{
		return 0;
	}

	while (str[i] == ' ' || str[i] == '0')
	{
		++i;
	}

	if (str[i] == '-' || isdigit(str[i]) || str[i] == '+')
	{
		long long number = 0;
		char sign = '+';

		if (str[i] == '-')
		{
			sign = '-';
			++i;
		}
		else if (str[i] == '+')
		{
			++i;
		}

		while (str[i] == '0')
		{
			++i;
		}

		bool isBig = false;
		int digitCount = 0;

		while (isdigit(str[i]))
		{
			if (digitCount > 10) // In VStudio19 this check is unnecessary
			{
				isBig = true;
				break;
			}
			number = (number * 10) + (str[i] - 48);
			++i;
			++digitCount;
		}

		if (sign == '-')
		{
			number *= -1;
		}

		if (isBig && sign == '+')
		{
			return INT_MAX;
		}
		else if (isBig && sign == '-')
		{
			return INT_MIN;
		}

		if (number > INT_MAX)
		{
			return INT_MAX;
		}
		else if (number < INT_MIN)
		{
			return INT_MIN;
		}

		return number;
	}
	else
	{
		return 0;
	}

}

int main()
{
	myAtoi("20000000000000000000");

	return 0;
}
