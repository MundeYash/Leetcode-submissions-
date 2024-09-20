/**
 * @param {number} n
 * @return {number}
 */
var hammingWeight = function(n) {
    // brute force approach 
    var count =0 ; 
    while (n){
        if (n&1)count ++ ; 
         n = n >> 1;
    }
    return count ; 
};