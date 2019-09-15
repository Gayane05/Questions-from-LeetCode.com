#include <iostream>
#include <algorithm>

class Solution {
public:
    int removeDuplicates(vector<int>& nums) 
    {
        std::vector<int>::iterator it;
        it = adjacent_find(nums.begin(),nums.end());
        
        if(it!=nums.end())
        {
            nums.erase(it);
            removeDuplicates(nums);
        }
        
        return nums.size();
    }
};

