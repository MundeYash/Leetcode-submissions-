class Solution {
public:
    int lengthOfLastWord(string s) {
        // don't include space and don't update 0 len word
        int lastWordLen =0 ; 
        int ans=0 ;
        int n =s.size();

        for (int i=0 ;i<n ;i++ ){
            char ch = s[i]; 

            if (ch==' '){
                // intialization
                if (ans!=0 ){
                    lastWordLen = ans;
                } 
                ans =0 ;
            }

            else{
                ans ++ ;
            }
        }

        // important condition of last word 
   
                if (ans!=0 ){
                    lastWordLen = ans;
                } 

        return lastWordLen;
        
    }
};