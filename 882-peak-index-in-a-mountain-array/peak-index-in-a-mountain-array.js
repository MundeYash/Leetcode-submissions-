/**
 * @param {number[]} arr
 * @return {number}
 */
var peakIndexInMountainArray = function(nums) {
    let n = nums.length ;
    var ans =-1;
    // binary search concept 
    let s=0 , e=n-1 ; 
    while (s<e ){
        let mid = (s + Math.floor((e-s)/2)); 
        if (nums[mid]<nums[mid+1]){
            // upward slope 
            s = mid + 1;
        }
        
        else{
            // peak element point mountain array 
           e = mid ;
        }
    }
    ans = s ;
    return ans ;
};