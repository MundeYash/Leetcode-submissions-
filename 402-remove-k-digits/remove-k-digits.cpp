class Solution {
public:
    string removeKdigits(string nums, int k) {
        int n = nums.size(); 

        stack<char > st ; 

        for (int i=0 ;i<n ;i++ ){

            while (!st.empty() && k>0 && st.top()>nums[i] ){
                st.pop() ; 
                k-- ; 

            }

            if (!st.empty() || nums[i] !='0'){
                st.push(nums[i]);
            }
        }


        while (!st.empty() && k-- ){
            st.pop();
        }

        if(st.empty()){
            return "0";
        }

        while (!st.empty()){
            nums[n-1]  =st.top();
            st.pop();
            n-- ;
        }
        return nums.substr(n);
    }
};