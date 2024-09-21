/**
 * @param {number[][]} mat
 * @return {number[]}
 */
function check(mat, i, j, n, m) {
    // Get the value of the current cell (i, j)
    let current = mat[i][j];

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

var findPeakGrid = function(mat) {
    var ans = [];
    // brute force approach 
    let n = mat.length;
    for (let i = 0; i < n; i++) {
        let m = mat[i].length;
        for (let j = 0; j < m; j++) {
            let curr = mat[i][j];
            if (check(mat, i, j, n, m) ) {
                ans =[i,j]; 
                return ans;
            }
        }
    }
    return ans;
};