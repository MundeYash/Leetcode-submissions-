class Solution {
public:
    int heightChecker(vector<int>& heights) {
        int n = heights.size();
        // create a copy and sort and compare 
        vector<int> expected (heights.begin(),heights.end()); 
        sort(expected.begin(),expected.end()); 
        int count = 0 ;
         for(int i=0 ;i<n ;i++ ){
            if (expected[i]!= heights[i])count ++ ; 
         }
         return count ; 
    }
};