class Solution {
    public int findPeakElement(int[] nums) {
        // brute force : peak element index is maximum element index 
        int ans =-1 ; 
        int maxValue = Integer.MIN_VALUE;
        int n  = nums.length ;
        for (int i=0 ;i<n ;i++ ){
            if (nums[i]>=maxValue){
                maxValue = nums[i];
                ans =i ;
            }
        }
        return ans;
    }
}