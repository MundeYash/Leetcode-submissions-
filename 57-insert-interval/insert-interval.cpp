class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        // concept : merge intervals (doable )

        intervals.push_back(newInterval)  ; 
        int n = intervals.size() ;
        // time : O(n) , space :O(n) for storing the ans 

        // step 1 : sort the intervals ; 
        sort(intervals.begin() , intervals.end()) ; 
        vector<vector<int>> ans ;

        // iterate and find answer 
        for (int i=0 ;i<n ;i++){
            if (ans.empty() || intervals[i][0]> ans.back()[1]){
                // unique interval h 
                ans.push_back(intervals[i] ) ;
            }
            else {
                // repeat interval h range update karo 
                ans.back()[1] = max (ans.back()[1] , intervals[i][1]) ;
            }
        }
        return ans ;
    }
};