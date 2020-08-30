#include <iostream>
#include <string>
#include <set>
#include <algorithm>
#include <ctype.h>

bool isLetter(char c, std::set<int>& symbols)
{
	if (symbols.find(c) != symbols.end())
	{
		return true;
	}
	else if (symbols.find(c - 32) != symbols.end())
	{
		return true;
	}
	return false;
}

bool isPalindrome(std::string s)
{

	// Runtime: 76 ms/52 ms
	// Memory Usage : 8.9 MB
	if (s.size() == 0)
	{
		return true;
	}
	std::set<int> mySet;

	for (int i = 1; i < 11; ++i)
	{
		mySet.insert(i + 47);
	}
	for (int i = 1; i < 27; ++i)
	{
		mySet.insert(i + 64);
	}

	//std::string str{ "" };
	//for (int i = 0; i < s.size(); ++i)
	//{
	//	if (mySet.find(s[i]) != mySet.end())
	//	{
	//		str.push_back(s[i]);
	//	}
	//	else if (mySet.find(s[i] - 32) != mySet.end())
	//	{
	//		str.push_back(s[i] - 32);
	//	}
	//}
	//for (int i = 0; i < str.size() / 2; ++i)
	//{
	//	if (str[i] != str[str.size() - i - 1])
	//	{
	//		return false;
	//	}
	//}
	//return true;

	//std::for_each(s.begin(), s.end(), [](char& c) {
	//	c = ::toupper(c); });
		int i = 0;
		int j = s.size() - 1;
		for (; i < s.size() / 2; ++i, --j)
		{
			while (!isLetter(s[i], mySet) && i != s.size())
			{
				++i;
			}
			while (!isLetter(s[j], mySet) && j >= s.size() / 2)
			{
				--j;
			}
			
			s[i] = toupper(static_cast<unsigned char>(s[i]));
			s[j] = toupper(static_cast<unsigned char>(s[j]));
			if (s[i] != s[j])
			{
				return false;
			}
			return true;
		}

}

int main()
{

	std::string s{ ".," };

	isPalindrome(s);

	return 0;
}

