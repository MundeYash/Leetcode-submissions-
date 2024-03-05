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
    bool solve(TreeNode* root , int value ){
        if (!root )return true ; 

        // working 
        bool leftCheck = solve (root ->left , value );
        bool rightCheck = solve(root ->right , value );
        if (leftCheck  and rightCheck and root ->val == value ){
            return true ; 
        }
        else{
            return false ;
        }
    }
    bool isUnivalTree(TreeNode* root) {
        if (!root )return true ; 
        int value = root->val ; 
        return solve(root , value );
    }
};