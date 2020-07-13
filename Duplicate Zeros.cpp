#include <iostream>
#include <vector>

void duplicateZeros(std::vector<int>& arr)
{
	// Runtime: 40 ms
	// Memory Usage : 10 MB
	//if (std::count(arr.begin(), arr.end(), 0) == 0)
	//{
	//	return;
	//}
	//int size = arr.size();
	//for (int i = 0; i < size; ++i)
	//{
	//	if (arr[i] == 0)
	//	{
	//		arr.insert(arr.begin() + i, 0);
	//		++i;
	//	}
	//}
	//arr.erase(arr.begin() + size, arr.end());

	std::vector<int> v(arr.size());
	int j = 0;
	for (int i = 0; j < arr.size(); ++i, ++j)
	{
		if (arr[i] != 0)
		{
			v[j] = arr[i];
		}
		else
		{
			v[j] = 0;
			++j;
		}
	}
	arr = v;
}
int main()
{
	std::vector<int> v{ 1,0,2,3,0,4,5,0 };
	duplicateZeros(v);
	return 0;
}
