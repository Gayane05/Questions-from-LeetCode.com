#include <iostream>
#include <vector>

// Given a matrix of m x n elements(m rows, n columns), return all elements of the matrix 
// in spiral order.
// 
// Example 1:
// 
// Input:
// [
// 	[ 1, 2, 3 ],
// 	[4, 5, 6],
// 	[7, 8, 9]
// ]
// Output : [1, 2, 3, 6, 9, 8, 7, 4, 5]

std::vector<int> spiralOrder(std::vector<std::vector<int>>& matrix) 
{

	// 22 / 22 test cases passed.
	// 	Runtime : 0 ms
	// 	Memory Usage : 7 MB

	int rowsCount = matrix.size();
	int colsCount = 0;
	std::vector<int> vec;

	if (rowsCount > 0)
	{
		colsCount = matrix[0].size();
	}
	int elementsCount = rowsCount * colsCount;
	int currentElementsCount = 0;
	int l = 0;

	while (currentElementsCount < elementsCount)
	{
		int i = 0 + l;
		int j = 0 + l;
		while (j < colsCount - l)
		{
			if (currentElementsCount < elementsCount)
			{
				vec.push_back(matrix[i][j++]);
				++currentElementsCount;
			}
			else
			{
				break;
			}
		}
		++i;
		j = colsCount - 1 - l;
		while (i < rowsCount - l)
		{
			if (currentElementsCount < elementsCount)
			{
				vec.push_back(matrix[i++][j]);
				++currentElementsCount;
			}
			else
			{
				break;
			}
		}
		--j;
		i = rowsCount - 1 - l;
		while (j >= 0 + l)
		{
			if (currentElementsCount < elementsCount)
			{
				vec.push_back(matrix[i][j--]);
				++currentElementsCount;
			}
			else
			{
				break;
			}
		}
		--i;
		j = 0 + l;
		while (i > 0 + l)
		{
			if (currentElementsCount < elementsCount)
			{
				vec.push_back(matrix[i--][j]);
				++currentElementsCount;
			}
			else
			{
				break;
			}
		}
		++l;
	}
	return vec;
}

int main()
{
	std::vector<std::vector<int>> matrix{ {1,2,3,4,5 },{6,7,8,9,10},{11,12,13,14,15},{16,17,18,19,20},{21,22,23,24,25} };
	spiralOrder(matrix);

	return 0;
}
