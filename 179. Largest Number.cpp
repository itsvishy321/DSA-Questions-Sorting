/*
Given a list of non-negative integers nums, arrange them such that they form the largest number and return it.

Since the result may be very large, so you need to return a string instead of an integer.

 

Example 1:

Input: nums = [10,2]
Output: "210"
*/

class Solution {
public:
        static bool cmp(string a , string b)
        {
            return a+b > b+a;
        }
    string largestNumber(vector<int>& nums) {
        
        vector<string> v;
        string ans="";

        //Making all the integer elements of the array to string
        for(int i = 0 ; i<nums.size() ; i++)
        {
            v.push_back(to_string(nums[i]));
        }
        
        //Sorting the New array w.r.t a comparator
        sort(v.begin() , v.end() , cmp);
        
        if(v[0] == "0")
            return "0";
        
        
        for(int i=0 ; i<v.size() ; i++)
        {
            ans += v[i];
        }
        
        return ans;
    }
};
