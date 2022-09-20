//Given two integer arrays nums1 and nums2, return an array of their intersection. 
//Each element in the result must be unique and you may return the result in any order.


class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        int i=0,j=0;
        set<int> temp;
        sort(nums1.begin(),nums1.end());
        sort(nums2.begin(),nums2.end());
        
        while(i<nums1.size() && j<nums2.size())
        {
            if(nums1[i]==nums2[j])
            {
                temp.insert(nums1[i++]);
                j++;
            }
            else if(nums1[i]<nums2[j])
            {
                i++;
            }
            else
            {
                j++;
            }
        }
        vector<int> ans;
        for(auto x:temp)
        {
            ans.push_back(x);
        }
        return ans;
    }
};
