#include <iostream>
#include <ctime>

constexpr auto size = 5;

void Sort(int* arr, int left, int right)
{
	int pivot = arr[(left + right) / 2];
	int i = left, j = right;
	int k;
	int f;

	while (i <= j)
	{
		while (arr[i] > pivot) i++;
		while (arr[j] < pivot) j--;
		if (i <= j) {

			k = arr[i];
			f = arr[j];

			std::swap(arr[i], arr[j]);
			i++;
			j--;
		}
	}

	if (j > left) Sort(arr, left, j);
	if (i < right) Sort(arr, i, right);
}


int main()
{
	int mat[size][size];
	int k = 0;
	int l = 0;

	srand(time(NULL));

	for (int i = 0; i < size; ++i)
	{
		for (int j = 0; j < size; ++j)
		{
			mat[i][j] = (rand() % 10) + 1;
			std::cout << mat[i][j] << " ";
		}
		std::cout << std::endl;
	}

	int vec[size * size];

	for (int i = 0; i < size; ++i)
	{
		for (int j = 0; j < size; ++j, ++k)
		{
			vec[k] = mat[i][j];
		}
	}

	Sort(vec, 0, (size * size) - 1);
	k = 0;
	std::cout << std::endl;
	for (int i = 0; i < size; ++i)
	{
		for (int j = 0; j < size; ++j, ++k)
		{
			mat[i][j] = vec[k];
			std::cout << mat[i][j] << " ";
		}
		std::cout << std::endl;
	}

	system("pause");
	return 0;
}