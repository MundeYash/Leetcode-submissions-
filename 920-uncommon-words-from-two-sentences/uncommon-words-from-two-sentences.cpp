class Solution {
public:
    vector<string> uncommonFromSentences(string s1, string s2) {
        vector<string> ans;
        // map based solution 
        unordered_map<string , int > freq1; 
     
        string temp ; 
        for (int i=0 ;i<s1.length(); i++ ){
            char ch = s1[i];
            if(ch==' '){
                // space means completion of word
                freq1[temp]++ ; 
                temp.clear();
            }
            else{
                temp.push_back(ch);

            }
        }
        // work for the last word 
        freq1[temp]++ ; 
        temp.clear();

         for (int i=0 ;i<s2.length(); i++ ){
            char ch = s2[i];
            if(ch==' '){
                // space means completion of word
                freq1[temp]++ ; 
                temp.clear();
            }
            else{
                temp.push_back(ch);

            }
        }
        // work for the last word 
        freq1[temp]++ ; 
        temp.clear();

        // comparison 
        for (auto it : freq1){
            if (it.second == 1  ){
                ans.push_back(it.first);
            }
        }
        return ans;
    }
};