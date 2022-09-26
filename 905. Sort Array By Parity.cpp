/*Given an integer array nums, move all the even integers at the beginning of the array followed by all the odd integers.

Return any array that satisfies this condition. */


// Approach 1

class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        
        int n=nums.size();
        vector<int> ans(n,0);
        int odd_index = n-1;
        int even_index = 0;
        for(int i=0 ; i<n ; i++)
        {
            if(nums[i] % 2 == 0)
            {
                ans[even_index++] = nums[i];                
            }
            else
            {
                ans[odd_index--] = nums[i];
            }
        }
        return ans;
    }
};

// Approach 2

class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        for(int i=0 , j=0 ; j<nums.size() ; j++)
        {
            if(nums[j]%2 == 0)
            {
                swap(nums[i++],nums[j]);
            }
        }
        return nums;
    }
};

