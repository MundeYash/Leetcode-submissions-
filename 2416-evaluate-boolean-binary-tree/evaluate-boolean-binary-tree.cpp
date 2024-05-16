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
    bool evaluateTree(TreeNode* root) {
        if (!root ->left and !root ->right ){
            return (root->val);
        }
        if (!root )return true ; 


        // leftAns 
        bool leftAns = evaluateTree(root->left );

        //rightAns 
         bool rightAns = evaluateTree(root->right );
        // working case 
        if (root ->val == 2 ){
            // OR operation
            return (leftAns || rightAns);
        }
        else {
            //And Operation 
               return (leftAns && rightAns);
        }

    }
};