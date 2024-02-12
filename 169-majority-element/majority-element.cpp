class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n = nums.size();
        // Brute Force Approach : Using Maps 
        unordered_map<int , int > mp ; 
        for (int i=0 ;i<n;i++ ){
            mp[nums[i]]++ ; 

        }
        // iterating over the map 
        for (auto it  : mp ){
            if (it.second >(n/2))return it.first ; 
        }
        return -1;
    }
};