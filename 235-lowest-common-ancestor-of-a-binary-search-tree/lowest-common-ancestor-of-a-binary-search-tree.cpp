/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {

         // base case 
        if (!root )return NULL ; 

        // recursive case 
        if (root == p || root ==  q ){
            return root ; 
        }

        TreeNode* leftAns = lowestCommonAncestor(root->left , p , q ) ; 
        TreeNode* rightAns = lowestCommonAncestor (root->right , p ,q ) ; 

        if (leftAns!= NULL  and rightAns != NULL ){
            // means both finded the answer 
            return root ; 
        }
        else if (leftAns!= NULL  and rightAns == NULL ){
            return leftAns ;

        }
        else if (leftAns== NULL and rightAns != NULL ){
            return rightAns ;
        }
        else {
            return NULL ; // no common ancestor exits 
        }
        
    }
};