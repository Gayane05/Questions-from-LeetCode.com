#include <iostream>
#include <vector> 

// Given a matrix of M x N elements (M rows, N columns),
// return all elements of the matrix in diagonal order as shown in the below image.
// Input:
// [
// 	[ 1, 2, 3 ],
// 	[4, 5, 6],
// 	[7, 8, 9]
// ]
// 
// Output: [1, 2, 4, 7, 5, 3, 6, 8, 9]

std::vector<int> findDiagonalOrder(std::vector<std::vector<int>>& matrix)
{
	// 32 / 32 test cases passed.
	// Runtime : 40 ms
	// Memory Usage : 18.6 MB
	
	int rowsCount = matrix.size();
	int colsCount = 0;

	if (rowsCount > 0)
	{
		colsCount = matrix[0].size();
	}
	std::vector<int> vec;

	if (rowsCount == 0 && colsCount == 0)
	{
		return vec;
	}
	else if (rowsCount == 1 && colsCount == 1)
	{
		vec.push_back(matrix[0][0]);
	}
	else
	{
		vec.push_back(matrix[0][0]);
		int i = 0;
		int j = 1;
		int elCount = 1;
		int c = (matrix.size() * matrix[0].size());

		while (elCount < c)
		{
			while (j >= 0 && i < rowsCount)
			{
				if (j >= colsCount && colsCount == 1)
				{
					j--;
					++i;
				}
				vec.push_back(matrix[i][j]);
				elCount++;
				++i;
				--j;
			}
			++j;
			if (i == rowsCount)
			{
				i--;
				++j;
			}
			while (i >= 0 && j < colsCount && i < rowsCount)
			{
				vec.push_back(matrix[i][j]);
				elCount++;
				--i;
				++j;
			}
			if (j == colsCount)
			{
				j--;
				++i;
			}
			++i;
		}
	}

	return vec;
}

int main()
{
	std::vector<std::vector<int>> matrix = {  };

	findDiagonalOrder(matrix);

	return 0;
}