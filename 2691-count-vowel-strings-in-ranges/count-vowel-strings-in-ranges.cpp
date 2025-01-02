class Solution {
public:
   bool isVowel(char c) {
    return (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u');
}

// Function to check if the string starts and ends with a vowel
bool startsAndEndsWithVowel( string s) {
    if (s.empty()) {
        return false; // Return false for empty strings
    }

    int lastIndex = s.length() - 1;
    return isVowel(s[0]) && isVowel(s[lastIndex]);
}
    vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& queries) {
        // simple check function for s
         vector<int>  ans ; 
        int n = words.size() ; 
         vector<int> countArr(n,0); 
         

         int q = queries.size(); 
         int count =0 ;

         for (int i=0 ;i<n ;i++){
            string s = words[i]; 
            if (startsAndEndsWithVowel(s)== true )count ++ ; 
            countArr[i] = count ;
            cout<<count<<" -- |";

         }
         cout<<endl;
         for (int i=0 ;i<q;i++){
            int l = queries[i][0]; 
            int r = queries[i][1];
           ans.push_back(countArr[r] - (l > 0 ? countArr[l - 1] : 0));
         }
        
    return ans;
    }
};