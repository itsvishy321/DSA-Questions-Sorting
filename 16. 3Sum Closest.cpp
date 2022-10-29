// Given an integer array nums of length n and an integer target, find three integers in nums such that the sum is closest to target.

// Return the sum of the three integers.

// You may assume that each input would have exactly one solution.

 

// Example 1:

// Input: nums = [-1,2,1,-4], target = 1
// Output: 2
// Explanation: The sum that is closest to the target is 2. (-1 + 2 + 1 = 2).


class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int n = nums.size(), ans = nums[0] + nums[1] + nums[2];
        for (int i = 0; i < n-2; ++i) {
            int l = i + 1, r = n - 1;
            while (l < r) {
                int sum3 = nums[i] + nums[l] + nums[r];
                if (abs(ans - target) > abs(sum3 - target)) // Update better ans
                    ans = sum3;
                if (sum3 == target) break;
                if (sum3 > target)
                    --r; 
                // Sum3 is greater than the target, to minimize the difference, we have to decrease our sum3
                
                else
                    ++l; 
                // Sum3 is lesser than the target, to minimize the difference, we have to increase our sum3
            }
        }
        return ans;
    }
};
