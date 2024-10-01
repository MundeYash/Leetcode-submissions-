class Solution {
public:
    bool helper (int index , string s , unordered_set<string>mp,vector<int>&dp ){
        // base case 
        if (index == s.size() ){
            return true;
        }

        if (dp[index]!=-1 )return dp[index];
        string temp = ""; 
        for (int i=index;i<s.size() ;i++ ){
            temp+= s[i]; 
            if (mp.find(temp)!=mp.end()){
                // means finded 
                if (helper(i+1,s,mp,dp))return dp[index]=true ;
            }
        }

        return dp[index]= false;
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string>mp ; 
        int n = s.size();
        
        for (auto i:wordDict){
            mp.insert(i);
        }

        //memoization adding 
        vector<int>dp(n+1,-1);
        return helper(0,s,mp,dp);
    }
};