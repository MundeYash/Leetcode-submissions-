/**
 * @param {number[]} nums
 * @return {number}
 */
var maxSubArray = function(nums) {
    // optimised approach : negative sum ; 
    let ans =-100000 ; 
    let sum =0 ; 
    let n = nums.length ; 
    for (let i=0 ;i<n ;i++ ){
        sum += nums[i]; 
          ans = Math.max(ans , sum );
        if (sum<0){
            // sum becomes negative 
            sum =0 ; 
        }
      
    }
    return ans ;
};