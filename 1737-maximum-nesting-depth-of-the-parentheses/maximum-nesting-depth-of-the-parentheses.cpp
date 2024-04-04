class Solution {
public:
    int maxDepth(string s) {
        stack<char > st ; 
        int n = s.size();
        int ans = 0 ;

        for (int i=0 ;i<n ;i++ ){
            char ch = s[i]; 

            if (ch=='('){
                st.push('(');
            }

            else if (ch==')'){
                if (!st.empty() && st.top() == '('){
                    int val = st.size(); 
                    if (val>ans )ans = val  ; 
                    st.pop();
                }
            }
        }

        return ans;
    }
};