class Solution {
public:
    int longestSquareStreak(vector<int>& nums) {
     // Sort the array to handle elements in ascending order
    sort(nums.begin(), nums.end());
    
    // Use a set for quick lookup
    unordered_set<long long> num_set(nums.begin(), nums.end());
    
    int longest_streak = -1;  // Start with -1 to return -1 if no valid streak is found
    
    // Iterate through each number in the sorted array
    for (int num : nums) {
        int current_streak = 1;
        long long current = num;
        
        // Try to build the square streak
        while (current <= 1e5 && num_set.find(current * current) != num_set.end()) {
            current = current * current;
            current_streak++;
        }
        
        // Check if the current streak is at least 2
        if (current_streak >= 2) {
            longest_streak = max(longest_streak, current_streak);
        }
    }
    
    return longest_streak;

    }
};