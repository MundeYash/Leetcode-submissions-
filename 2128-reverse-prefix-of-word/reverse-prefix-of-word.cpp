class Solution {
public:
    void reverse(string &word , int st , int end ){
        while (st<end){
            swap(word[st], word[end]); 
            st++ ; 
            end--;
        }
        return ;
    }
    string reversePrefix(string word, char ch) {
        int n = word.size(); 
        int st = 0  ,end =-1; 
        if (word.find(ch)< n){
            end = word.find(ch);
            reverse(word, st , end);
        }
        return word;
    }
};