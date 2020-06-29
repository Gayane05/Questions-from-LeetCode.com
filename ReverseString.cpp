#include <iostream>
#include <vector>

void reverseString(std::vector<char>& s) 
{
	// Runtime: 48 ms
	// Memory Usage : 23.5 MB
	// Another approach is not to use swap() function do it in C-style.
	int size = s.size();
	int j = size - 1;
	for (int i = 0; i < size / 2; ++i, --j)
	{
		std::swap(s[i],s[j]);
	}
}

int main()
{
	std::vector<char> str{ 'H','a','n','n','a', 'h' };
	reverseString(str);

	return 0;
}
