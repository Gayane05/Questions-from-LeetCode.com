#include <iostream>
#include <vector>
#include <algorithm>

template<typename T>
void SelectionSort(std::vector<T>& vec)
{
	for (int i = 0; i < vec.size(); ++i)
	{
		int min = i;
		for (int j = i + 1; j < vec.size(); ++j)
		{
			if (vec[min] > vec[j])
			{
				min = j;
			}
		}
		std::swap(vec[i], vec[min]);
	}
}

int main()
{
	std::vector<char> nums { 'c', 't', 'f', 'g', 'j' };

	SelectionSort(nums);

	return 0;
}
