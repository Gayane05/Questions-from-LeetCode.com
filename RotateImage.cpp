#include <iostream>
#include <vector>


void rotate(std::vector<std::vector<int>>& matrix)
{

	// Runtime: 4 ms
	// Memory Usage : 7.2 MB
	int size = matrix.size();

	for (int i = 0; i < size; ++i)
	{
		for (int j = i; j < size; ++j)
		{
			std::swap(matrix[i][j], matrix[j][i]);
		}
	}

	int k = size - 1;
	for (int i = 0; i < size; ++i)
	{
		for (int j = 0, k = size - 1; j < size / 2; ++j, --k)
		{
			std::swap(matrix[i][j], matrix[i][k]);
		}
	}

	//// Another approach - with rotating all the time to the right
	//1 2 3 first step -> 4 1 2 second step ->	7 4 1
	//4 5 6				7 5 3					8 5 2
	//7 8 9				8 9 6					9 6 3

	//1 2 3 4 first step ->	5 1 2 3 second step -> 9 5 1 2  third step -> 13 9 5 1  last step(for internal elements) -> 13 9 5 1
	//5 6 7 8					9 6 7 4				   13 6 7 3				  14 6 7 2										14 10 6 2
	//9 10 11 12				13 10 11 8			   14 10 11 4			  15 10 11 3									15 11 7 3
	//13 14 15 16				14 15 16 12			   15 16 12 8			  16 12 8 4										16 12 8 4

}

int main()
{
	std::vector<std::vector<int>> matrix = { {1,2,3},{4,5,6},{7,8,9} };
//	std::vector<std::vector<int>> matrix = { {1,2,3,4}, {5,6, 7, 8}, {9,10,11,12 },{13,14,15,16} };

	rotate(matrix);

	for (int i = 0; i < matrix.size(); ++i)
	{
		for (int j = 0; j < matrix.size(); ++j)
		{
			std::cout << matrix[i][j] << " ";
		}
		std::cout << std::endl;
	}
	return 0;
}