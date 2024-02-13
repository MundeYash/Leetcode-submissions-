class Solution {
public:
// valid palindrome function 
bool checkPalindrome(string s ){
    int n = s.size();
    // Two pointer method 
    int st =0 , end = n- 1 ; 

    while (st< end ){
        if (s[st]!= s[end])return false;
        st++ ; 
        end -- ;
    }
    return true ;
}
    string firstPalindrome(vector<string>& words) {
         string ans ; 
         int n = words.size(); 

         for (int i= 0 ;i<n ;i++ ){
             string temp = words[i];
             if (checkPalindrome(temp)){
                 return temp ;
             }
         }
         return ans;

    }
};