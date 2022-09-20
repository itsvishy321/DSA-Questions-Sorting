// Given an array of distinct integers arr, find all pairs of elements with the minimum absolute difference of any two elements.

// Return a list of pairs in ascending order(with respect to pairs), each pair [a, b] follows

// a, b are from arr
// a < b
// b - a equals to the minimum absolute difference of any two elements in arr



class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        vector<vector<int>> pairs;
        
        //minimum absolute difference -> mad
        int mad = INT_MAX;        
        
        sort(arr.begin(),arr.end());
        
        for(int i=1 ; i<arr.size() ; i++)
        {
            int diff = arr[i]-arr[i-1];
            if(diff == mad)
            {
                pairs.push_back({arr[i-1],arr[i]});
            }
            
            else if(diff<mad)
            {
                pairs.clear();
                mad=diff;
                pairs.push_back({arr[i-1],arr[i]});
            }
        }
        return pairs;
        

    }
};
