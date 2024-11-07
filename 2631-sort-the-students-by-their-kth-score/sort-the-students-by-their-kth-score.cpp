class Solution {
public:
    vector<vector<int>> sortTheStudents(vector<vector<int>>& score, int k) {
        // using another matrix for answer storage 
        int n = score.size() ; 
        vector<pair<int , int>> arr ; // value , corresponding index 
        for (int i=0 ;i<n ;i++ ){
            arr.push_back(make_pair(score[i][k], i));
        }

        sort(arr.begin(),arr.end()) ; // sort the arr based on decreasing order of value 
        reverse(arr.begin(),arr.end());
        vector<vector<int>> ans ;
        for (int i=0 ;i<arr.size() ;i++ ){
            int index  = arr[i].second ;
            ans.push_back(score[index]);

        }
        return ans;
    }
};