class Solution {
public:
    string customSortString(string order, string s) {
        string ans ; 

        // step 1: creation of unordered map for storing the frequecies 
        unordered_map<char , pair<int , int > > mp ; 
        int n = order.size();// size of the string order : 

        // find the frequency of string s with the index of first occurence 
        for (int i=0 ;s[i]!='\0'; i++ ){
             

           // if current character of string s is going to be  added to the map first time  than increase frequency and store the index of first occurence 
            if (mp.find(s[i])== mp.end()){
                mp[s[i]].first ++ ;
                mp[s[i]].second = i ;
            }
            else{

                // if f current character of string s is already added in the map  than just update increase frequency.
                mp[s[i]].first ++ ;
            }
        }


    // step3 : add the character with their occurences to the string ans if they exists in the order string and simultaneously reduce the frequency 
    vector<pair<int , char >> temp ;
        for (int i=0 ;i<n ;i++ )
        {
            if (mp.find(order[i]) != mp.end()){
                // means exists 
                int k = mp[order[i]].first ;
                while (k--){
                    ans += order[i];
                }
                mp[order[i]].first =0;

            } 
            
        }

        for (auto it: mp ){
            if (it.second.first !=0 ){
                
                // if does not exists 
                temp.push_back(make_pair(it.second.second , it.first ));

            
            }
        }
        sort(temp.begin() , temp.end()) ;
        for (int i=0 ;i<temp.size(); i++ ){
            char ch = temp[i].second ;
            int k =mp[ch].first ;
            while ( k--){
                ans += ch ;
            }
            mp[ch].first =0 ;
        }
        return ans;

        // return "";  
    }
};