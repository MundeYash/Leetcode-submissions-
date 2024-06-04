class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int n = nums.size(); 
        // negative method approach 
        int ans =-1 ; 

        for (int i=0 ;i<n ;i++ ){
            int index = abs(nums[i]);
            if (nums[index]<0){
                ans = index ;
            }

            // update the index 
            nums[index] *=-1;
        }

        return ans;
    }
};