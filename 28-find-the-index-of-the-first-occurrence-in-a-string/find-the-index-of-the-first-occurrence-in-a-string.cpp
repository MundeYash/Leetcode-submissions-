class Solution {
public:
    int strStr(string haystack, string needle) {
        bool result  = false ;
        int ans = -1 ;
        int n = haystack.size() ; 
        int m = needle.size();
        if (haystack.find(needle)<haystack.length()){
            return haystack.find(needle);
        }
        else{
            return -1;
        }
    }
};