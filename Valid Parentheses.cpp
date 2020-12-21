#include <iostream>
#include <string>
#include <stack>

bool isValid(std::string s)
{

	// 91 / 91 test cases passed.
	// Runtime : 0 ms
	// Memory Usage : 6.5MB 

	std::stack<char> st;
	if (s.size() == 1)
	{
		return false;
	}

	if (s[0] == ')' || s[0] == '}' || s[0] == ']')
	{
		return false;
	}

	int actionsCount = 0;

	for (int i = 0; i < s.size(); ++i)
	{
		if (s[i] == '(' || s[i] == '{' || s[i] == '[')
		{
			st.push(s[i]);
			actionsCount++;
		}
		else if (s[i] == ')' || s[i] == '}' || s[i] == ']')
		{
			if (s[i] == ')' && !st.empty() && st.top() == '(')
			{
				st.pop();
				actionsCount++;
			}
			else if (s[i] == '}' && !st.empty() && st.top() == '{')
			{
				st.pop();
				actionsCount++;
			}
			else if (s[i] == ']' && !st.empty() && st.top() == '[')
			{
				st.pop();
				actionsCount++;
			}
		}
	}

	if (!st.empty())
	{
		return false;
	}
	if (actionsCount != s.size())
	{
		return false;
	}

	return true;
}

int main()
{
	std::string parentheses{ ")(){}" };
	isValid(parentheses);

	return 0;
}