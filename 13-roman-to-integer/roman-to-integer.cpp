class Solution {
public:
    int romanToInt(string s) {
        unordered_map<char, int> mp = {
        {'I', 1},
        {'V', 5},
        {'X', 10},
        {'L', 50},
        {'C', 100},
        {'D', 500},
        {'M', 1000}
    };
    
    int number = 0;
    int n = s.size() ;
    // last value will always be added ;
    number+=mp[s[n-1]];
    // previous smaller value concept : 
    for (int i=s.size()-1 ;i>=1 ;i-- ){
        if (mp[s[i-1] ]< mp[s[i]]){
            number -= mp[s[i-1]];
        }
        else{
            number += mp[s[i-1]];
        }
    }
   

    return number;
    }
};