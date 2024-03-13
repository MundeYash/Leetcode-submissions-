class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
             
        vector<int> ans ; 
        int n = mat.size(); 
        
         // concept  : ordered_map ; 
         
         map<int , vector<int>> mp ; 
         
         for (int i=0 ;i<n ;i++ ){
             for (int j=0 ;j<mat[i].size() ;j++ ){
                 int index = (i+j); 
                 mp[index].push_back(mat[i][j]);
             }
         }
         
         // iterating over the map to get the answer in the desired format 
         int count =0 ; 
         
         for (auto i: mp ){
             
             if (count%2==0 ){
                 reverse(i.second.begin()  , i.second.end());
             }
             for (auto j: i.second ){
                 ans.push_back(j);
             }
             count ++ ;
         }
         return ans;
    }
};