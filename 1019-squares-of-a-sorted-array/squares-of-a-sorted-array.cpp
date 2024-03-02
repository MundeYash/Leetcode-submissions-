class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        // sort the elements without the sign //0 1 3 4 10
        int n = nums.size(); 
    // optimised approach : Two pointer approach , time : O(N) , space : O(n-> due to using of extra array )
    int start= 0 ,end =n-1 ; 
    // since the array is sorted in increasing (just consider the absolute value means only maginitue )
    vector<int> ans (n,0);
    int index =n-1 ;
    while(start<= end and index>=0 ){
        if (abs(nums[start])>= abs(nums[end])){
            // means negative value is greater 
            ans[index --] = (nums[start]* nums[start ]); 
            start ++ ; 
        
        }
        else{
            ans[index -- ] = (nums[end]* nums[end ]) ; 
            end -- ; 
        }
    }
        return ans ; 
    }
};