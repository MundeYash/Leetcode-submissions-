class Solution {
public:
    vector<int> constructTransformedArray(vector<int>& nums) {

        vector<int> ans;
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            int value = nums[i];
            if (value == 0) {
                ans.push_back(0);
            } else {
                int index = value + i;
                // Adjust index to wrap around correctly
                int adjustedIndex = (index % n + n) % n;
                ans.push_back(nums[adjustedIndex]);
            }
        }

        return ans;
    }
};