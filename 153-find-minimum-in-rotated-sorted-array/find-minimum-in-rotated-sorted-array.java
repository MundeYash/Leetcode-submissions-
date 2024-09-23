class Solution {
    public int findMin(int[] nums) {
        // smallest element in the array is our pivot element 
        // brute force 
        int mini= Integer.MAX_VALUE ; 

        for (int i=0 ;i<nums.length ;i++ ){
            if (nums[i]<mini)mini = nums[i];
        }
        return mini;
    }
}