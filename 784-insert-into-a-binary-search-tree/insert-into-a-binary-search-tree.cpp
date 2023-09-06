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
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        // time : O(log n ) , space : O(n -> recursive stack space )
        // base case 
        if (root == NULL ) {
            // first time insertion 
            root = new TreeNode(val) ;
            return root ;
        }

        // recursive case 
        if (root ->val < val ){
            // inserted in the right side 
            root->right = insertIntoBST(root ->right , val ) ;


        }
        else{
            root ->left = insertIntoBST(root ->left , val ) ;
        }
        return root ;
        
    }
};