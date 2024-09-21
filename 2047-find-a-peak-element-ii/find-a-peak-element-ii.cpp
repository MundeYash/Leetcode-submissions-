class Solution {
public:
    bool check(const vector<vector<int>>& mat, int n, int m, int i, int j) {
    // Get the value of the current cell (i, j)
    int current = mat[i][j];

    // Check upward neighbor (i-1, j)
    if (i - 1 >= 0 && mat[i - 1][j] >= current) {
        return false;
    }

    // Check downward neighbor (i+1, j)
    if (i + 1 < n && mat[i + 1][j] >= current) {
        return false;
    }

    // Check left neighbor (i, j-1)
    if (j - 1 >= 0 && mat[i][j - 1] >= current) {
        return false;
    }

    // Check right neighbor (i, j+1)
    if (j + 1 < m && mat[i][j + 1] >= current) {
        return false;
    }

    // If all neighbors are smaller, return true
    return true;
}


    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        vector<int> ans ; 
        int n = mat.size(); 
        for (int i=0 ;i<n ;i++ ){
            int m = mat[i].size(); 
            for (int j=0 ;j<m ;j++){
                if (check(mat,n,m,i,j )== true ){
                    return {i,j};
                }
            }
        }
        return ans;
    }
};