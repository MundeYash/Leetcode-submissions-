class Solution {
public:
    void solve(int index , vector<int>nums , vector<int>&output , set<vector<int>> &s )
    {
        // base case
        if (index>=nums.size()){
            s.insert(output);
            return ;
        }

        // pick the element 
        output.push_back(nums[index]);
        solve(index+1, nums, output , s);
        output.pop_back(); 

        solve(index + 1, nums , output , s );
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans ; 
        set<vector<int>> s ; 
        vector<int> output;
        int index =0 ; 

        solve(index , nums , output ,s );
        for (auto i:s ){
            ans.push_back(i);
        }
        return ans;
    }
};