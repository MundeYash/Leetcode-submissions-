class Solution {
public:
    vector<int> sortArrayByParityII(vector<int>& nums) {
        // concept : two arrays and placing elements 
        vector<int> ans , odd ,even ; 
        int n = nums.size(); 
        for (int i=0 ;i<n ;i++ ){
            int value = nums[i]; 
            if (value &1 )odd.push_back(value ); 
            else even.push_back(value );
        }
        for (int i= 0;i<n/2 ;i++ ){
            ans.push_back(even[i]);
            ans.push_back(odd[i]); 
            
        }

        return ans;
    }
};