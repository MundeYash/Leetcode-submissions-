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
        // simple approch:Post Order traversal & recursion based 

        // base case 
        if (!root ){
            return NULL ; 
        }

        if (root->val == p->val || root->val == q->val  ){
            return root  ;
        }

        TreeNode* leftAns = lowestCommonAncestor(root->left , p, q ); 
        TreeNode* rightAns = lowestCommonAncestor(root->right , p , q );

        // work 
        if (leftAns == NULL and rightAns == NULL ){
            return NULL ; 
        }
      
        else if (leftAns != NULL and rightAns!=NULL ){
            return root ;
        }
          else if (left!=NULL || rightAns !=NULL ){
            if (leftAns!=NULL )return leftAns ; 
            else return rightAns;
        }

    }
};