class Solution {
public:
 int reverse(int n ){
     if (n>=0){

     
     int copy = n ; 
     long long int ans =0  ; 
     while (copy != 0 ){
         int ld = (copy %10   ) ; 
         ans = ans * 10 + ld ; 
         copy  = copy /10 ; 


     }
      return ans ;
     }
     else {

         return false ;
     }
 }
    bool isPalindrome(int x) {
         if (reverse(x) == x ){
             return true ;
         }
         else {
             return false ;
         }
        
    }
};