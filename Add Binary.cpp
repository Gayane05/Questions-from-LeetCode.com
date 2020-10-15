#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

std::string addBinary(std::string a, std::string b)
{
	// 294 / 294 test cases passed.
	// Runtime : 0 ms
	// Memory Usage : 6.8 MB

	std::vector<int> v1;
	std::vector<int> v2;
	std::string res;
	for (int i = a.size() - 1; i >= 0; --i)
	{
		v1.push_back(a[i] - 48);
	}
	for (int i = b.size() - 1; i >= 0; --i)
	{
		v2.push_back(b[i] - 48);
	}
	int l = 0;
	int mn = -1;
	int size = std::min(a.size(), b.size());

	for (int i = 0; i < size; ++i)
	{
		if (v1[i] == 1 && v2[i] == 1)
		{
			if (mn == 1)
			{
				res.push_back('1');
			}
			else
			{
				res.push_back('0');
			}
			mn = 1;
		}
		else if ((v1[i] == 1 && v2[i] == 0) || v1[i] == 0 && v2[i] == 1)
		{
			if (mn == 1)
			{
				res.push_back('0');
				mn = 1;
			}
			else
			{
				res.push_back('1');
				mn = 0;
			}
		}
		else
		{
			if (mn == 1)
			{
				res.push_back('1');
				mn = 0;
			}
			else
			{
				res.push_back('0');
				mn = 0;
			}
		}
	}

	if (v1.size() > v2.size())
	{
		for (int i = v2.size(); i < v1.size(); ++i)
		{
			if (v1[i] == 1)
			{
				if (mn == 1)
				{
					res.push_back('0');
					mn = 1;
				}
				else
				{
					res.push_back('1');
					mn = 0;
				}
			}
			else
			{
				if (mn == 1)
				{
					res.push_back('1');
					mn = 0;
				}
				else
				{
					res.push_back('0');
					mn = 0;
				}
			}
		}
	}
	
	else if (v1.size() < v2.size())
	{
		for (int i = v1.size(); i < v2.size(); ++i)
		{
			if (v2[i] == 1)
			{
				if (mn == 1)
				{
					res.push_back('0');
					mn = 1;
				}
				else
				{
					res.push_back('1');
					mn = 0;
				}
			}
			else
			{
				if (mn == 1)
				{
					res.push_back('1');
					mn = 0;
				}
				else
				{
					res.push_back('0');
					mn = 0;
				}
			}
		}
	} 
	if (mn == 1)
	{
		res.push_back('1');
	}

	std::reverse(res.begin(), res.end());

	return res;
}

int main()
{
	std::string a{ "1010" };
	std::string b{ "1011" };
	addBinary(a, b);

	return 0;
}