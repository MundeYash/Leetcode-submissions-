class Solution {
public:
    int reverse(int x) {

        // check if the number is negative 
        bool isNegative = false; 
        if (x<= INT_MIN ||x>= INT_MAX)return 0;

        if (x<0 ) {
            isNegative = true ; 
            x = -x ;
        }

       
    int ans =0 ;
        while (x>0 ){
            int ld = x%10 ; 

            if ((ans>INT_MAX /10 ) || (ans< INT_MIN /10 )) return 0 ;
            ans = ans *10 + ld ; 

            x =  x /10 ;


        }


        if (isNegative){
            return (-ans) ;
        }


        return ans;
        
    }
};