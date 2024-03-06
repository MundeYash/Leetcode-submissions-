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
    bool solve(TreeNode* root , int target ){
       if (!root )return false ; 

        if (target == root ->val and (!root ->left and !root ->right ) ){// root must be leaft node for this condition to be true 
            return true ; 
        }

        bool leftAns = solve(root ->left , target - root ->val ); 
        bool rightAns = solve(root ->right , target - root ->val );

        if(leftAns || rightAns ){
            return true ; 
        }
        return false;
       

    }
    bool hasPathSum(TreeNode* root, int targetSum) {
        if (!root )return false; 
        return solve(root , targetSum);
    }
};