class Solution {
public:
vector<int> generateDiff(string s){
    vector<int> ans ; 

    for (int i=0 ;i<s.size()-1;i++ ){
        ans.push_back((s[i+1]-s[i]));
    }
    // sort(ans.begin() , ans.end());
    return ans;

}
    string oddString(vector<string>& words) {
        string ans =""; 
        vector<vector<int>> diff ;
        int n = words.size();
        // Step1 : find the difference integer array 
     
        for (int i=0 ;i<n ;i++ ){
           vector<int> sol = generateDiff(words[i]);
           diff.push_back(sol); 
        }

        // comparison 
        

         for(int i=1 ;i<diff.size()-1;i++ ){
            if (diff[i]!= diff[i+1] and diff[i]!= diff[i-1]){
                return words[i];
            }
        }

        if (diff[0]!= diff[1]){
            return words[0];
        }
       

        if (diff[n-1]!= diff[n-2]){
            return words[n-1];
        }

        return "";
    }
};