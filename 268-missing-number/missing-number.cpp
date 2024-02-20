class Solution {
public:
    int missingNumber(vector<int>& nums) {
        // concept : xor 
        int n = nums.size();
        int ans = n ; 
        for (int i=0 ;i<n ;i++ ){
            ans = ans ^ nums[i]; 
            ans = ans^ i ; 

        }
        return ans; 
    }
};