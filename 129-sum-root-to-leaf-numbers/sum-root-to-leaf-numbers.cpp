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
    void solve(TreeNode* root , int number , int &ans ){
        //base case
        if (!root )return ; 
        number = number *10 + (root->val ) ; 
        if (root->left== NULL and root->right== NULL ){
            // means leaf node , number is computed 
            ans += number ; 
            return ;
        }

        if (root->left!= NULL  ){
            solve(root->left , number , ans ) ;
        }
        if (root ->right != NULL ){
            solve(root->right , number , ans ) ;
        }
    }
    int sumNumbers(TreeNode* root) {
        // optimised way 
        int ans = 0 ; 
        int number =0 ; 
        solve(root , number , ans );
        return ans;
    }
};