class Solution {
public:
    bool isPowerOfFour(int n) {
        if (n <= 0) {
        return false;  // Powers of 3 are positive integers
    }
    
    while (n % 4 == 0) {
        n /= 4;
    }
    
    return n == 1;
    }
};