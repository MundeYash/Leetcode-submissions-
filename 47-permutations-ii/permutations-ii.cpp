class Solution {
public:
void solve(int index ,vector<int>nums, int n , set<vector<int>> &ans ){
        // base case 
        if (index >=n ){
            ans.insert(nums);
            return ;
        }

        // recursive case 
        for (int i=index;i<n ;i++){

            swap(nums[index],nums[i]);
            solve(index + 1, nums,n, ans ) ; 
            swap(nums[index], nums[i]);
        }
        
        
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>>ans ; 
        set<vector<int>>s;
        int index =0 ; 
        solve(index , nums , n , s);

        for(auto i:s  ){
            ans.push_back(i);
        }
        return ans;
    }
};