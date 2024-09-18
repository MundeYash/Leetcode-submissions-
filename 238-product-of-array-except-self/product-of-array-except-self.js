/**
 * @param {number[]} nums
 * @return {number[]}
 */
var productExceptSelf = function(nums) {
    // prefix Product and suffix Product concept will be used 
    let n = nums.length;
    let pref=1 , suff =1 ;
    let prefixProd = new  Array(n);; 
    let suffixProd = Array(n);
    let ans=  new Array(n);


    prefixProd[0] =1 ; 
    suffixProd[n-1] = 1;
    
    for(let i= 1 ;i<n ;i++ ){
        pref *= nums[i-1];
        prefixProd[i] = pref;
    }
    for (let i=n-2 ;i>=0 ;i-- ){
        suff *=nums[i+1];
        suffixProd[i] = suff ;
    }

    // actual calculation 
    for (let i=0 ;i<n ;i++ ){
        nums[i] = (prefixProd[i] * suffixProd[i]);
    }
    return nums;

};