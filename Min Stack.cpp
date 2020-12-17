#include <iostream>
#include <vector>
#include <stack>

class MinStack 
{
public:
	/** initialize your data structure here. */

	// Stack from vector
	// Runtime : 220 ms
	// Memory Usage : 16.2 MB
	/*MinStack() 
	{
		m_stack.resize(1);
		i = -1;
		m_size = 0;
	}

	void push(int x) 
	{
		++i; 
		++m_size;
		if (i == m_stack.size())
		{
			m_stack.resize(m_stack.size() * 2);
		}

		m_stack[i] = x;
	}

	void pop() 
	{
		--i;
		--m_size;

		if (i <= m_stack.size() / 4)
		{
			m_stack.resize(m_stack.size() / 2);
		}
	}

	int top() 
	{
		if (m_stack.size() != 0)
		{
			return m_stack[i];
		}
		return -1;
	}

	int getMin() 
	{
		m_min = m_stack[0];
		for (int i = 1; i < m_size; ++i)
		{
			if (m_stack[i] < m_min)
			{
				m_min = m_stack[i];
			}
		}
		return m_min;
	}

	int m_min;
	int i;
	std::vector<int> m_stack;
	int m_size;*/

	// Using std::stack<int>
	MinStack()
	{

	}

	void push(int x)
	{
		stack.push(x);
		if (!min_stack.empty())
		{
			if (x < min_stack.top())
			{
				min_stack.push(x);
			}
		}
		else
		{
			min_stack.push(x);
		}
	}

	void pop()
	{
		if (!stack.empty() && !min_stack.empty())
		{
			if (stack.top() == min_stack.top())
			{
				min_stack.pop();
			}
			stack.pop();
		}
	}

	int top()
	{
		if (!stack.empty())
		{
			return stack.top();
		}
		return -1;
	}

	int getMin()
	{
		if (!min_stack.empty())
		{
			return min_stack.top();
		}
		return -1;
	}

	std::stack<int> stack;
	std::stack<int> min_stack;

};

int main()
{
    
	MinStack* obj = new MinStack();
	obj->push(0);
	obj->push(1);
	obj->push(0);
	int param_4 = obj->getMin();
	int param_3 = obj->top();
	int param_5 = obj->getMin();

	return 0;
}
