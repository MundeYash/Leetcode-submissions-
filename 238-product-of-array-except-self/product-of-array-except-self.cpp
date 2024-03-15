class Solution {
public:
    //function for finding the prefix product 
    void preProd(vector<int>&ans ,vector<int>arr ){
        int n = arr.size(); 
        int prod =1 ;
        for (int i=0 ;i<n ;i++ ){
            ans[i] = prod ; 
            prod *= arr[i];
        }
        return ;

    }

     void suffProd(vector<int>&ans ,vector<int>arr ){
        int n = arr.size(); 
        int prod =1 ;
        for (int i=n-1 ;i>=0 ;i-- ){
            ans[i] = prod ; 
            prod *= arr[i];
        }
        return ;

    }
    vector<int> productExceptSelf(vector<int>& nums) {
        // concept : prefix product and suffix product ; 
            int n = nums.size(); 
        vector<int> ans(n,0);
        vector<int>prefix(n,0); 
        preProd(prefix,nums);
        vector<int>suffix(n,0);
        suffProd(suffix,nums);

        for (int i=0 ;i<n;i++ ){
            ans[i]  = (prefix[i]* suffix[i]);
        }
        return ans ; 
    

    }
};