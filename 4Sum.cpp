// Given an array nums of n integers, return an array of all the unique quadruplets [nums[a], nums[b], nums[c], nums[d]] such that:

// 0 <= a, b, c, d < n
// a, b, c, and d are distinct.
// nums[a] + nums[b] + nums[c] + nums[d] == target
// You may return the answer in any order.

 

// Example 1:

// Input: nums = [1,0,-1,0,-2,2], target = 0
// Output: [[-2,-1,1,2],[-2,0,0,2],[-1,0,0,1]]

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> res;
        int n=nums.size(); 
        sort(nums.begin(),nums.end());
        for(int i=0 ; i<n ; i++)
        {
            long long target3 = target - nums[i];
            for(int j=i+1 ; j<n ; j++)
            {
                long long target2 = target3 - nums[j];
                int front = j+1;
                int back = n-1;
                
                while(front < back)
                {
                    int sum = nums[front] + nums[back];
                    
                    if(sum < target2) front++;
                    
                    else if(sum > target2) back--;
                    
                    else
                    {
                        vector<int> quadruplet(4,0);
                        quadruplet[0] = nums[i];
                        quadruplet[1] = nums[j];
                        quadruplet[2] = nums[front];
                        quadruplet[3] = nums[back];
                        res.push_back(quadruplet);
                        
                        //Checking duplicates of 3rd number
                        while(front < back && quadruplet[2]==nums[front]) front++;
                        
                        //Checking duplicates of 4th number
                        while(front < back  && quadruplet[3]==nums[back]) back--;
                    }    
                }
                
                //Checking duplicates of 2nd number
                while(j<n-1 && nums[j]==nums[j+1]) j++;
            }
            
            //Checking duplicates of 1st number
            while(i<n-1 && nums[i]==nums[i+1]) i++;
        }
        return res;
    }
};
