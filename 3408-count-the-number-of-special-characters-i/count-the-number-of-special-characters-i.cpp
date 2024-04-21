class Solution {
public:
    int numberOfSpecialChars(string word) {
        //map based solution 
        int n = word.size(); 
        unordered_map<char , int > mp ; 
        for (int i=0 ;i<n ;i++ ){
            mp[word[i]]++ ;
        }

        int count =0 ;
        for (auto it: mp ){
            char ch = it.first  ; 
            if (ch>='a' && ch<='z'){
                // lowercase 
                if (mp.find(ch-'a' + 'A')!= mp.end() ){
                    count ++ ;
                }
            }
        }
        return count ; 
    }
};