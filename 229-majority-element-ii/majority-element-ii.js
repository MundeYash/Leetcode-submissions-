/**
 * @param {number[]} nums
 * @return {number[]}
 */
var majorityElement = function (nums) {
    var ans = [];
    let n = nums.length;
    // edge cases for single element existence
    if (n == 1) {
        ans.push(nums[0]);
        return ans;
    }
    // step 1: sorting the array 
    nums = nums.sort((a, b) => (a - b)); // increasing order

    let count = 1;
    for (let i = 1; i < n; i++) {
        if (nums[i - 1] == nums[i]) count++;
        else {
            if (count > (n / 3)) {
                ans.push(nums[i - 1]);
            }
            count = 1;
        }




    }

    if (count > (n / 3)) {
        ans.push(nums[n - 1]);
    }

    return ans;
};