class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        // concept : sliding window and (count the number of one and number of zero and update the length )
          int max_length = 0;
    int count = 0;
    unordered_map<int, int> seen; // Store the first index where count is seen
    seen[0] = -1; // Initialize with count 0
    for (int i = 0; i < nums.size(); ++i) {
        if (nums[i] == 0)
            count -= 1;
        else
            count += 1;
        if (seen.find(count) != seen.end()) { // If count is seen before, calculate length
            max_length = max(max_length, i - seen[count]);
        } else {
            seen[count] = i; // Store the index where count is seen for the first time
        }
    }
    return max_length;
    }
};