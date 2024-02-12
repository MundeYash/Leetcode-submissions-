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
    pair<int , int > fastDia (TreeNode* root ){
        pair<int , int> ans; 
        if (!root ){
            ans.first = 0  ; 
            ans.second =  0 ; 
            return ans;

        }

        //recursive 
        pair<int , int > leftAns = fastDia(root->left ); 
        pair<int , int > rightAns  = fastDia(root ->right );
        int op1 = leftAns.first ; 
        int op2 = rightAns.first ; 
        int op3 = (leftAns.second + rightAns.second ) ; 
        ans.first = max(op1 , max(op2 , op3 )) ; 
        ans.second = max(leftAns.second , rightAns.second ) + 1 ; 
        return ans;
    }
    int diameterOfBinaryTree(TreeNode* root) {
        //Optimsed Approach : finding the diameter in the optimsed way int O(n) time complexity 
        return fastDia(root ).first ; 

    }
};