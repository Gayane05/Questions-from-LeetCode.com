#include <iostream>
#include <string>

std::string countAndSay(int n) 
{
	// With recursion 
	// 18 / 18 test cases passed.
	//	Runtime : 8 ms
	//	Memory Usage : 6.6 MB
	if (n == 1)
	{
		return "1";
	}
	else if (n == 2)
	{
		return "11";
	}
	else
	{
		std::string str = countAndSay(n - 1);
		std::string result{ "" };
		int j = 0;
		for (int i = 0; i < str.size(); ++i)
		{
			int count = 1;
			j = i + 1;
			while (str[i] == str[j])
			{
				count++;
				++j;
				++i;
			}
			result += std::to_string(count) + str[i];
		}
		return result;
	}
}

int main()
{
	countAndSay(5);
}
