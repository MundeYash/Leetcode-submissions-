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
    int maxDepth(TreeNode* root) {
        // concept : any traversal + condition  check 
        if (!root )return 0 ; 
        int leftAns = maxDepth (root->left ) ; 
        int rightAns = maxDepth (root ->right ) ; 
        return max(leftAns ,rightAns )  + 1; 


    }
};