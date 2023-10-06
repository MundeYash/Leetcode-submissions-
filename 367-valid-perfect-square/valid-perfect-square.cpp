class Solution {
public:
    bool isPerfectSquare(int num) {
        int  s=0 ,e = num; 
        int ans =-1 ;
        while (s<=e ){
            long long  mid = (s+e)/2 ; 
            long long  value = (mid * mid );
            if (value == num ){
                ans = mid ; 
                break ;
            }
            else if (value > num ){
                e = mid -1 ; 
            }
            else{
                s = mid + 1;
            }
        }
        
        if ((ans * ans )== num  ){
            return true ;
        }
        
        return false ;
        
    }
};