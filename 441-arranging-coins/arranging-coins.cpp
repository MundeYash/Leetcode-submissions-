class Solution {
public:
    int arrangeCoins(int n) {
         long long low = 0, high = n;
    long long mid, total;
    
    while (low <= high) {
        mid = low + (high - low) / 2;
        total = mid * (mid + 1) / 2;
        
        if (total == n) {
            return mid;
        } else if (total < n) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    
    return high;
    }
};