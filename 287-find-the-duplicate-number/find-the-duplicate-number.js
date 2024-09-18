/**
 * @param {number[]} nums
 * @return {number}
 */
var findDuplicate = function(nums) {
    let n = nums.length; 
    // sorting approach will work 
     nums.sort( (a,b)=> a-b );
     for (let i=0 ;i<n-1 ;i++ ){
        if (nums[i]== nums[i+1])return nums[i];
     }
     return -1 ;
};