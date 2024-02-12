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
    int height (TreeNode* root ){
        if (!root )return 0 ; 

        int leftAns = height (root ->left );
        int rightAns  = height(root ->right );
        return max(leftAns , rightAns ) + 1;
    }
    // function for fidning the diameter of the tree
int diameter(TreeNode *root)
{
    // time : O(N^2)  ,space : O(n)
    if (!root) return 0;
       

    int op1 = diameter(root->left);
    int op2 = diameter(root->right);
    int op3 = height(root->left) + height(root->right);
    return max(op1, max(op2,op3));
}
    int diameterOfBinaryTree(TreeNode* root) {
        if (root == NULL )return 0 ;
       return diameter (root );
        
        
    }
};