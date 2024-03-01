class Solution {
public:
   
    string maximumOddBinaryNumber(string s) {
        int n = s.size(); 
        // count number of 1 in the string 
        int one = 0 ; 
        for (int i=0 ;i<n ;i++ ){
            if (s[i]=='1')
            {
                one ++ ; 
            }
        }
    
    string temp (n,'0');
    temp[n-1]='1';
    one-- ;

    // convert the maximum odd number 
    int i=0 ;
    while (one>0 and i <=n-2){
        temp[i]= '1';
        one-- ; 
        i++;


    }
 
    return temp;





        
    }
};