// Given an integer array nums, return all the triplets [nums[i], nums[j], nums[k]] such that i != j, i != k, and j != k, and nums[i] + nums[j] + nums[k] == 0.

// Notice that the solution set must not contain duplicate triplets.

 

// Example 1:

// Input: nums = [-1,0,1,2,-1,-4]
// Output: [[-1,-1,2],[-1,0,1]]


class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<vector<int>> ans;
        
        int n=nums.size();
        
        for(int i=0 ; i<n ; i++)
        {
            int j=i+1;
            int k=n-1;
            while(j<k)
            {
                int sum = nums[i]+nums[j]+nums[k];
                if(sum > 0) k--;
            
                else if(sum<0) j++;
                
                else
                {
                    vector<int> triplet = {nums[i],nums[j],nums[k]};
                    ans.push_back(triplet);
                    
                    //Skipping duplicate elements of nums[j] for nums[i]
                    while(j<k && nums[j]==triplet[1]) j++;
                    
                    //Skipping duplicate elements of nums[k] for nums[i]
                    while(j<k && nums[k]==triplet[2]) k--;
                }
            }
            
            //Skipping duplicate elements of nums[i]
            while(i+1<n && nums[i]==nums[i+1]) i++;
        }
        return ans;
    }
};
