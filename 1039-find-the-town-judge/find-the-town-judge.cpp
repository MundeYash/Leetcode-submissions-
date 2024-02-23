class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        // Create an array to count the number of trusts each person receives
    vector<int> trustCounts(n + 1, 0);

    // Iterate through the trust relationships and count trusts received
    for (const auto& relation : trust) {
        trustCounts[relation[1]]++;
    }

    // Check if there exists a person who is trusted by exactly n - 1 people
    for (int i = 1; i <= n; ++i) {
        if (trustCounts[i] == n - 1) {
            // Check if this person trusts nobody
            bool trustsNobody = true;
            for (const auto& relation : trust) {
                if (relation[0] == i) {
                    trustsNobody = false;
                    break;
                }
            }
            if (trustsNobody) {
                return i; // This person is the town judge
            }
        }
    }

    return -1; // No town judge found
    }
};