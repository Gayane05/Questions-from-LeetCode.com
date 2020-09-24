#include <iostream>
#include <vector>

bool checkIfExist(std::vector<int>& arr) 
{
	// 104 / 104 test cases passed.
	// Runtime : 12 ms
	// Memory Usage : 9.9 MB
	
	if (arr.size() == 0 || arr.size() == 1)
	{
		return false;
	}

	for (int i = 0; i < arr.size(); ++i)
	{
		for (int j = i + 1; j < arr.size(); ++j)
		{
			if (arr[i] * 2 == arr[j] || (arr[j] != 0 && arr[i] / arr[j] == 2 && arr[i] % arr[j] == 0))
			{
				return true;
			}
		}
	}
	return false;
}

int main()
{
	std::vector<int> array{ 3, 1, 7, 11 };

	checkIfExist(array);

	return 0;
}
