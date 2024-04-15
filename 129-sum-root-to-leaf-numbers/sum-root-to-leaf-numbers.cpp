/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:

// array to number conversion 
    int a2Value(vector<int> arr  ){
       int n = arr.size(); 
       int ans =0 ; 
       for (int i=0 ;i<n ;i++ ){
        ans += (arr[i] * pow(10,(n-i-1))); 
       } 

       return ans;
    }
// helper function for solve 

    void solve(TreeNode* root , vector<int> path , int&ans ){
        if (!root )return ; 

        path.push_back(root->val);
        if(!root->left && !root ->right ){
            // means one solution 
            ans += a2Value (path  );
            return ;
        }

        solve(root->left , path ,ans );
        solve(root ->right , path , ans );
    }
    int sumNumbers(TreeNode* root) {
        if(!root )return 0 ; 

        vector<int>path ; 
        int ans =0  ; 
        solve(root , path , ans ); 
        return ans;
    }
};