#include <iostream>
#include <vector>

std::vector<int> getRow(int rowIndex)
{
	// Runtime: 0.50 ms
	// Memory Usage : 6.9 MB
	int numRows = rowIndex + 1; // Number of rows
	std::vector<std::vector<int>> triangle(numRows);

	// Generate Pascal's triangel
	int l = numRows;
	for (int i = 0; i < numRows; ++i)
	{
		triangle[i].resize(numRows - l + 1);
		int first_m = 0;

		// Fill columns
		for (int j = 0; j <= numRows - l; ++j)
		{
			if (i == 0)
			{
				triangle[i][j] = 1;
			}
			else if (i == 1)
			{
				triangle[i][j] = 1;
			}
			else
			{
				if (j == 0 || j == numRows - l)
				{
					triangle[i][j] = 1;
				}
				else
				{
					int second_m = first_m + 1;
					triangle[i][j] = triangle[i - 1][first_m] + triangle[i - 1][second_m];
					++first_m;
				}
			}
		}
		--l;
	}


	std::vector<int> row;
	// In every row elements count and row number are equal.
	for (int j = 0; j < numRows; ++j)
	{
		row.push_back(triangle[rowIndex][j]);
	}

	return row;
}

int main()
{
	getRow(3);
	return 0;
}