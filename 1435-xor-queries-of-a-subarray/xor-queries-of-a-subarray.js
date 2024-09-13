/**
 * @param {number[]} arr
 * @param {number[][]} queries
 * @return {number[]}
 */
var xorQueries = function(arr, queries) {
    var ans =[] ; 
    for (let i=0 ;i<queries.length;i++ ){
        let value =0;
        let left = queries[i][0]; 
        let right = queries[i][1]; 
        while (left<=right ){
            value ^=arr[left]; 
            left++;
        }
        ans.push(value);
    }
    return ans;

};