class Solution {
public:
    int numberOfSpecialChars(string word) {
        // map based solution 
        int n = word.size(); 
        unordered_map<char ,int> freq; 
        unordered_map<char , bool > update ; 

        for (int i=n-1 ;i>=0 ;i--){
            char ch = word[i];
            if (ch>='A' && ch<='Z'){
                // upper case 
                freq[ch] = i ;
            }
        }

        for (int i=0 ;i<n ;i++ ){
            char ch = word[i]; 
            if (ch>='a' && ch<='z'){
                if (update.find(ch)== update.end() ){
                    // means first time occurrence 
                    if (freq[ch-'a' + 'A']> i) update[ch] = true ;
                    else update[ch] = false ;
                    
                }
                else{
                    // means already exists 
                    if (update[ch] == false  || freq[ch-'a' + 'A']< i){
                         update[ch] = false ;
                    }
                }
            }
        }
        int count =0 ; 
        for (auto it: update ){
            if (it.second== true ){
                count ++ ;
            }
        }
        return count ; 
    }
};