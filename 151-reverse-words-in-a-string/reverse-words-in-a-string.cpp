class Solution {
public:
    string reverseWords(string s) {
        int n = s.size(); 
        string ans ="", temp = ""; 
        stack<string>st ;

        for (int i=0 ;i<n ;i++ ){
            char ch = s[i]; 
            if(ch == ' '){
                // means one word complete 
                if (temp.size()!=0 ){
                    st.push(temp); 
                    
                }
                temp.clear();

            }
            else {
                temp.push_back(ch);
            }
        }


        // adding the last word to the stack 
        if (temp.size()!=0 ){
                    st.push(temp); 
                    
                }
         temp.clear();

         while (!st.empty()){
            ans += st.top(); 
            st.pop(); 
            ans.push_back(' ');

         }

        ans.pop_back();
         return ans;

    }
};