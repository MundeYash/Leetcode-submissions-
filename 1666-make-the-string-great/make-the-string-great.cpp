class Solution {
public:

    // for find the inverse character 
    char findInverse(char ch ){
        if (ch>='a' && ch<='z'){
            // lower case character 
            return (ch-'a'+ 'A');
        }

        else {
           return (ch-'A' + 'a'); 
        }
    }
    string makeGood(string s) {
        // stack based approach :
        // time : O(n ) , space : O(n)


        stack<int> st ; 
        int n = s.size(); 

        for (int i=0 ;i<n ;i++ ){
            char ch = s[i]; 

            if (st.empty()){
                st.push(ch);
            }
            else if (!st.empty() && findInverse(ch) == st.top()){
                st.pop();
            }
            else{
                st.push(ch);
            }
        }


        string ans="";

        while (!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }
        reverse(ans.begin() ,ans.end()); 
        return ans;
        
    }
};