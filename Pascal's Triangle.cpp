#include <iostream>
#include <vector>

std::vector<std::vector<int>> generate(int numRows)
{

	// 15 / 15 test cases passed.
	// Runtime : 0 ms
	// Memory Usage : 6.8 MB
	
	std::vector<std::vector<int>> triangle(numRows);

	int l = numRows;
	for (int i = 0; i < numRows; ++i)
	{
		triangle[i].resize(numRows - l + 1);
		int first_m = 0;

		for (int j = 0; j <= numRows - l; ++j)
		{
			if (i == 0)
			{
				triangle[i][j] = 1;
			}
			else if( i == 1 )
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
	return triangle;
}

int main()
{
	generate(5);
	return 0;
}