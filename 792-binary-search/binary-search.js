/**
 * @param {number[]} nums
 * @param {number} target
 * @return {number}
 */
var search = function(nums, target) {
    let n = nums.length  ; 
    var ans = -1 ; 
    let start =0, end =n-1 ; 
    while (start<=end ){
        let mid = (Math.floor(start+ (end-start)/2)); 
        let value = nums[mid];
        if (value == target ){
            ans = mid ; 
            break ;
            
        }
        else if (value > target){
            end = mid-1 ; 

        }else{
            start = mid + 1;
        }
    }

    return ans;
    
};