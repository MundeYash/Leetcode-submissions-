class Solution {
public:
    bool isPowerOfThree(int n) {
        if (n <= 0) {
        return false;  // Powers of 3 are positive integers
    }
    
    while (n % 3 == 0) {
        n /= 3;
    }
    
    return n == 1;
    }
};