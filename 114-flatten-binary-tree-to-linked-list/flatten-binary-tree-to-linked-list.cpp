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
    void flatten(TreeNode* root) {

        // make all the changes in the root itself 

        TreeNode* pre , * curr ; 

        curr =root ; 
        while (curr ){
            if (curr->left !=  NULL ){
                // predecessor node exists 
                pre = curr->left; 

                while (pre->right ){
                    pre = pre->right ; 
                }

                pre ->right = curr ->right;
                curr ->right = curr->left ; 

                // remaining connection for left pointer of current node 
                curr->left = NULL;

            }
            curr = curr->right ;

        }

       
        
    }
};