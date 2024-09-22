class Solution {
public:
    bool reportSpam(vector<string>& message, vector<string>& bannedWords) {
        // sort both and compare
         
        int n = message.size(); 
        int m = bannedWords.size();
        int count =0 ;
        // map based 
        unordered_map<string , int > mp ; 
        for (int j=0 ;j<m ;j++ ){
            mp[bannedWords[j]]++ ;
        }

        for (int i=0 ;i<n ;i++ ){
            if (mp.find(message[i])!= mp.end()){
                count ++ ;
            }
        }
        int ans=  (count>=2)?1:0 ; 
        return ans;
       
        
    }
};