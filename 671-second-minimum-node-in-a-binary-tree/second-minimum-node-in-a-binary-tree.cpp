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
    void solve (TreeNode* root , long long  &first , long long  &second ){
        if (!root )return ; 
        if (first>root ->val ){
            first = root ->val;
        }

        else if (second != first and root->val <second and(root ->val != first )){
            second = root ->val;
        }
        solve(root->left , first , second ); 
        solve(root->right ,first , second );
    }
    int findSecondMinimumValue(TreeNode* root) {
        if (!root )return - 1;
        long long  firstMin = LONG_MAX ; 
        long long  secondMin= LONG_MAX ; 
        // any traversal format 
        solve(root , firstMin , secondMin);
        if (secondMin == LONG_MAX )return -1 ;
        return secondMin;
    }
};