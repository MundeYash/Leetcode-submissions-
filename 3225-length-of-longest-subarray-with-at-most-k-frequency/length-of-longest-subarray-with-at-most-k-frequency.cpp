class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        int start = 0, end = 0;
    int n = nums.size();
    int maxLen = 0;
    unordered_map<int, int> freq;
    int countExceedingK = 0; // Track count of characters exceeding k

    for (int end = 0; end < n; end++) {
        freq[nums[end]]++;
        if (freq[nums[end]] == k + 1) {
            countExceedingK++;
        }

        while (countExceedingK > 0) {
            freq[nums[start]]--;
            if (freq[nums[start]] == k) {
                countExceedingK--;
            }
            if (freq[nums[start]] == 0) {
                freq.erase(nums[start]);
            }
            start++;
        }

        maxLen = max(maxLen, end - start + 1);
    }

    return maxLen;
    }
};