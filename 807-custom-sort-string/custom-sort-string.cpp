class Solution {
public:
    string customSortString(string order, string s) {
        // optimised self implementation 
        /*we have to sort string s , according to indexes of order string */
        int n = s.size() ; 
        int m = order.size() ;

        // step 1: create map to store string s ke (char , (firstIndex , count ))
        unordered_map<char  ,pair<int , int>> mp; 
        for (int i=0;i<n ;i++ ){
            // first time occur character 
           if ( mp.find(s[i])==mp.end()){
                // store first index of that character
                mp[s[i]].first = i ; 

           }
           // update the count 
           mp[s[i]].second ++ ;
        }
        string ans = "" ;

        for (int i=0;i<m ;i++ ){
            char ch = order[i] ;
           int count =  mp[ch].second ;
           string temp = "" ; 
           while (count -- ){
            temp.push_back(ch);
           }
           ans += temp ;
           mp.erase(ch);

        }

        // work for remaining character of s string 
        vector<pair<int , string >> arr   ; 
        for (auto it: mp ){
            char ch = it.first;
            int index = it.second.first ; 
            int count = it.second.second ; 
            string temp ="";
            while (count -- ){
                temp.push_back(ch);
            }
            arr.push_back(make_pair(index , temp));
        }

        sort(arr.begin(),arr.end()) ;
        for (int i=0 ;i<arr.size();i++){
            ans += arr[i].second ;
        }
        return ans;

    }
};