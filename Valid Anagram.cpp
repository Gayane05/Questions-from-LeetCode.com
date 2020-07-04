#include <iostream>
#include <string>
#include <map>
#include <algorithm>
#include <unordered_map>

bool isAnagram(std::string s, std::string t)
{
	// Runtime: 64ms, 72 ms
	// Memory Usage : 7.2, 7.3 MB
	/*if (s.size() != t.size())
	{
		return false;
	}
	std::map<char, int> letters_s;
	std::map<char, int> letters_t;
	for (int i = 0; i < s.size(); ++i)
	{
		letters_s[s[i]]++;
		letters_t[t[i]]++;
	}
	for (int i = 0; i < t.size(); ++i)
	{
		std::map<char,int>::iterator it_t = letters_t.find(t[i]);
		std::map<char, int>::iterator it_s = letters_s.find(t[i]);
		if (it_s == letters_s.end() || it_t->second != it_s->second)
		{
			return false;
		}
	}
	return true;*/
	

	//Idea not by me
	// Runtime: 28ms, 32 ms
	// Memory Usage : 7.6MB, 7.4 MB
	/*if (s.size() != t.size())
	{
		return false;
	}
	std::unordered_map<char, int> letters;
	for (int i = 0; i < s.size(); ++i)
	{
		letters[s[i]]++;
		letters[t[i]]--;
	}
	for (int i = 0; i < letters.size(); ++i)
	{
		if (letters[s[i]] != 0)
		{
			return false;
		}
	}
	return true;*/

	// Runtime: 96 ms
	// Memory Usage : 7.4 MB
	/*if (s.size() != t.size())
	{
		return false;
	}
	std::sort(s.begin(), s.end());
	std::sort(t.begin(), t.end());
	int size = s.size();
	for (int i = 0; i < size; ++i)
	{
		if (s[i] != t[i])
		{
			return false;
		}
	}
	return true;*/

	// Runtime: 96 ms
	// Memory Usage : 7.2 MB
	if (s.size() != t.size())
	{
		return false;
	}
	std::sort(s.begin(), s.end());
	std::sort(t.begin(), t.end());
	if (s != t)
	{
		return false;
	}
	return true;
}

int main()
{
	std::string s = "anagram";
	std::string t = "nagaram";
	isAnagram(s,t);
	return 0;
}

