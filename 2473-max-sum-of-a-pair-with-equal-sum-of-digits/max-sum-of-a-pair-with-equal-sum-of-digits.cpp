class Solution {
public:
    int digitSum(int n) {
        int sum = 0;
        while (n) {
            sum += (n % 10);
            n = n / 10;
        }
        return sum;
    }
    int maximumSum(vector<int>& nums) {
        // map based solution
        int n = nums.size();
        unordered_map<int, vector<int>> mp;
        for (int i = 0; i < n; i++) {
            int number = nums[i];
            int sum = digitSum(number);
            mp[sum].push_back(number);
        }
        int ans = INT_MIN;

        for (auto it : mp) {
            int n = it.second.size();
            if (n > 1) {
                int maxi =
                    INT_MIN; // Initialize max to the smallest possible integer
                int secondMax = INT_MIN; // Initialize second max to the
                                         // smallest possible integer

                for (int i = 0; i < n; i++) {
                    if (it.second[i] > maxi) {
                        secondMax = maxi; // Update second max before max
                        maxi = it.second[i];    // Update max to the current element
                    } else if (it.second[i] > secondMax && it.second[i] != maxi) {
                        secondMax = it.second[i]; // Update second max
                    }
                }
                cout<<maxi<<secondMax;
                if (secondMax == INT_MIN)secondMax = maxi;
                int value = (maxi + secondMax) ;
                cout<<value<<endl;
                ans = max(value, ans);
            }
        }
        if (ans == INT_MIN)
            ans = -1;
        return ans;
    }
};