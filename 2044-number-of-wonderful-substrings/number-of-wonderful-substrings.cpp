class Solution {
public:

    bool valid(string s , int st, int end ){
        int count =0 ;
        vector<int>freq(26,0); 
        for (int i=st;i<=end ;i++ ){
            freq[s[i]-'a']++ ;
        }

        for (int i=0 ;i<26 ;i++ ){
            if (freq[i]!=0 && freq[i]%2 !=0 )count ++ ;
        }

        if (count>1 )return false;
        return true ;
    }
    long long wonderfulSubstrings(string word) {
        // long long count =0 ; 
        // int n= word.size(); 

        // for (int i=0 ;i<n ;i++ ){
        //     for (int j=i ; j<n ;j++ ){
        //         if (valid(word, i, j))count++ ;
        //     }
        // }
        // return count ;

        long long count = 0;
    int n = word.size();
    unordered_map<int, int> prefixFreq; // Prefix frequency map
    prefixFreq[0] = 1; // Initialize with an empty string

    int currPrefix = 0; // Current prefix frequency

    for (int i = 0; i < n; i++) {
        currPrefix ^= 1 << (word[i] - 'a'); // Update current prefix frequency
        count += prefixFreq[currPrefix]; // Add count of substrings with the same prefix
        // Update prefix frequency map
        for (int j = 0; j < 26; j++) {
            int nextPrefix = currPrefix ^ (1 << j); // Next possible prefix
            count += prefixFreq[nextPrefix]; // Add count of substrings with the next possible prefix
        }
        prefixFreq[currPrefix]++; // Update prefix frequency map
    }

    return count;
    }
};