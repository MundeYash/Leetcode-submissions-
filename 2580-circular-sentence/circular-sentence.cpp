class Solution {
public:
    bool isCircularSentence(string sentence) {
        int n = sentence.size(); 
        if(sentence[0] != sentence[n-1])return false;
        string temp ;


        for (int i=0 ;i<n ;i++ ){
            char ch = sentence[i]; 
            if (ch==' '){
                if (sentence[i-1]!= sentence[i+1])return false;
                temp.clear();
            }
            else{
                temp.push_back(ch);
            }
        }

        return true ; 
    }
};