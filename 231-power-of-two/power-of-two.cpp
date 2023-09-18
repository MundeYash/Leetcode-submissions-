class Solution {
public:
    bool isPowerOfTwo(int n) {
       // bit manipulation approach 
       long long ans = n ;
       
        return ((ans!=0 )&& (ans & (ans-1))==0);
    }
};