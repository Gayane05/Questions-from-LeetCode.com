#include <iostream>
#include <vector>
#include <algorithm>

std::vector<int> sortedSquares(std::vector<int>& A) 
{
	// Runtime: 108 ms
	// Memory Usage : 25.8 MB
	for (int i = 0; i < A.size(); ++i)
	{
		A[i] *= A[i];
	}
	std::sort(A.begin(), A.end());
	return A;
}

int main()
{
	std::vector<int> v{ -4,-1,0,3,10 };
	sortedSquares(v);

	return 0;
}
