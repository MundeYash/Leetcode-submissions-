class Solution {
public:
    bool isPowerOfTwo(int n) {
        if(n==1 )return true ; 
        long long int ans =n ;

        return ((ans!=0 ) && (ans&(ans-1))==0);
    
        
    }
};