class Solution {
public:
    int xorFind(int left , int right , vector<int>arr ){
        int ans =0 ;
        for (int i=left ; i<=right;i++ ){
            ans ^=arr[i];
        }
        return ans;
    }
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
          vector<int> ans ; 
          int q = queries.size(); 
          int n = arr.size(); 
          for (int i=0 ;i<q ;i++ ){
            int left  = queries[i][0]; 
            int right = queries[i][1];
            int value  = xorFind(left, right , arr );
            ans.push_back(value);
          }
          return ans;
    }
};