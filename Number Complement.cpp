#include <iostream>
#include <vector>

int findComplement(int num) 
{

	// Runtime: 0 ms
	// Memory Usage : 6.7 MB
	int complementNumber = 0;
	std::vector<int> binaryRep; // Keep binary representation of num

	if (num == 0)
	{
		return 1;
	}

	while (num > 0)
	{
		if (num % 2 == 0)
		{
			binaryRep.push_back(0);
		}
		else
		{
			binaryRep.push_back(1);
		}
		num /= 2;
	}
	
	// 1110012 = 1⋅25+1⋅24+1⋅23+0⋅22+0⋅21+1⋅20 = 5710
	for (int i = 0; i < binaryRep.size(); ++i)
	{
		if (binaryRep[i] == 1)
		{
			complementNumber += 0 * pow(2, i); // For reversing
		}
		else
		{
			complementNumber += 1 * pow(2, i);
		}
	}
	return complementNumber;
}

int main()
{

	findComplement(5); // 2

	return 0;
}
