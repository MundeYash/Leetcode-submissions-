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

void check(TreeNode* root  , TreeNode* target , TreeNode* &ans ){
    if (!root  )return ; 

    // check condition 
    if (root->val == target ->val){
        ans = root ; 
        return ;

    }

    check(root->left , target , ans ) ; 
    check(root->right , target , ans) ; 


}
    TreeNode* getTargetCopy(TreeNode* original, TreeNode* cloned, TreeNode* target) {
        //search a node in binary tree , Time : O(n ) , space : O(h->recursive stack space  )
         TreeNode* ans = NULL ; 
         check(cloned , target , ans ) ;

         return ans;



        
    }
};