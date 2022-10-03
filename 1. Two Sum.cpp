// Given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target.

// You may assume that each input would have exactly one solution, and you may not use the same element twice.

// You can return the answer in any order.


class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();
        vector<int> ans;
//         Making pair of (index,value)
        
        vector<pair<int,int>> p;
        for(int i = 0 ; i<n ; i++)
        {
            p.push_back(make_pair(nums[i],i));
        }
        
        
        sort(p.begin(),p.end());
        int j = n-1;
        for(int i=0;i<j;)
        {
            if(p[i].first+p[j].first == target)
            {
                return {p[i].second,p[j].second};

            }
            
            else if(p[i].first + p[j].first > target)
                j--;
            else
                i++;
            
        }
        return {-1,-1};
    }
};
