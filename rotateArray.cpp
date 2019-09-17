// Given an array, rotate the array to the right by k steps, where k is non-negative.

class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        std::vector<int> store(k);


	for (int i = nums.size()-k, j = 0; i < nums.size(); ++i,++j)
	{
		store[j] = nums[i];
		
	}
	
	for (int i = nums.size() - 1; i > k - 1; --i)
	{
		nums[i] = nums[i - k];
	}
	int i = 0;
	for (int el : store)
	{
		nums[i] = el;
		++i;
	}


        
    }
};
