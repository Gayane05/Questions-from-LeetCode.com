#include <iostream>
#include <string>
#include <algorithm>

std::string addStrings(std::string num1, std::string num2)
{
	// Runtime: 4 ms
	// Memory Usage : 7 MB
	// Second submit
	// Runtime: 0 ms
	// Memory Usage: 7 MB

	std::string result{""};

	int n = std::min(num1.size(), num2.size());
	bool mn = 0;
	int ch = 0; // number

	int l = 0;
	int k = 0;
	for (int i = 1; i <= n ; ++i)
	{
		l = num1.size() - i;
		k = num2.size() - i;
		ch = (num1[l] - 48) + (num2[k] - 48);
		if (mn)
		{
			ch += 1;
		}
		if (ch >= 10)
		{
			result.push_back(ch % 10 + 48);
			ch /= 10;
			mn = true;
		}
		else
		{
			result.push_back(ch + 48);
			mn = false;
		}
	}

	if (num1.size() > num2.size())
	{
		for (int i = --l; i >= 0; --i/*i < num1.size() - n; ++i*/)
		{
			ch = num1[i] - 48;
			if (mn)
			{
				ch += 1;
			}
			if (ch >= 10)
			{
				result.push_back(ch % 10 + 48);
				ch /= 10;
				mn = true;
			}
			else
			{
				result.push_back(ch + 48);
				mn = false;
			}
		}
	}

	if (num1.size() < num2.size())
	{
		for (int i = --k; i >= 0; --i/*i < num2.size() - n; ++i*/)
		{
			ch = num2[i] - 48;
			if (mn)
			{
				ch += 1;
			}
			if (ch >= 10)
			{
				result.push_back(ch % 10 + 48);
				mn = true;
			}
			else
			{
				result.push_back(ch + 48);
				mn = false;
			}
		}
	}

	if (mn)
	{
		result.push_back(49);
	}

	std::reverse(result.begin(), result.end());
	return result;

}
int main()
{
	addStrings("9", "98");

	return 0;
}