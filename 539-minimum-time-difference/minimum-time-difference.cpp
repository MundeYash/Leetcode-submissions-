class Solution {
public:

int change(string s ){
     int hours = (s[0] - '0') * 10 + (s[1] - '0');
    int minutes = (s[3] - '0') * 10 + (s[4] - '0');
    return hours * 60 + minutes;
}

    int findMinDifference(vector<string>& timePoints) {
        int n = timePoints.size();
    vector<int> ans(n);

    for (int i = 0; i < n; i++) {
        ans[i] = change(timePoints[i]);
    }

    sort(ans.begin(), ans.end());

    int minDifference = INT_MAX;
    for (int i = 1; i < n; i++) {
        minDifference = min(minDifference, ans[i] - ans[i - 1]);
    }

    // Consider the difference between the first and last time points
    int circularDifference = 24 * 60 - (ans[n - 1] - ans[0]);
    minDifference = min(minDifference, circularDifference);

    return minDifference;
    }
};