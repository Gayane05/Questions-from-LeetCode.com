#include <iostream>
#include <string>

int strStr(std::string haystack, std::string needle)
{

	// 77 / 77 test cases passed.
	// Without using std::find() function.
	// Runtime: 4 ms
	// Memory Usage: 6.8 MB
	bool check = true;
	if (needle.size() == 0)
	{
		return 0;
	}
	else if (needle.size() > haystack.size())
	{
		return -1;
	}
	else
	{
		bool check = true;
		int j = 0;
		int i = 0;
		int l = 0;
		
		while (j != haystack.size())
		{
			if (haystack[j] == needle[i])
			{
				if(j + needle.size() - 1 < haystack.size() &&
				(haystack[j + needle.size() - 1] == needle[needle.size() - 1]))
				{
					l = j;
					check = true;
					for (; i < needle.size(); )
					{
						if (needle[i] == haystack[j])
						{
							++i;
							++j;
						}
						else
						{
							check = false;
							break;
						}
					}
					if (check)
					{
						return l;
					}
				}
			}
			j = l + 1;
			++l;
			i = 0;
		}
		return -1;
	}
	
}

int main()
{
	std::string haystack{ "mississippi" };
	std::string needle{ "sipp" };

	strStr(haystack, needle);

	return 0;
}
