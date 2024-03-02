class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        // sort the elements without the sign //0 1 3 4 10
        int n = nums.size(); 
        for (int i=0 ;i<n ;i++ ){
            nums[i] = (nums[i]* nums[i]);
        }
        sort(nums.begin() , nums.end()); 
        return nums ; 
    }
};