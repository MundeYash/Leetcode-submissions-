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
    pair<int ,int > solve(TreeNode* root ){
        // base case 
        pair<int ,int> ans; 
        if (!root ){
            ans.first = 0 ; 
            ans.second =0 ;
            return ans;
        }

        pair<int ,int >  leftAns = solve(root ->left ) ;
        pair<int ,int > rightAns = solve(root ->right ); 

        int op1 = leftAns.first ; 
        int op2 = rightAns.first ; 
        int op3 = (leftAns.second + rightAns.second )+ 1; 
        ans.first = max(op1, max(op2,op3 )); 
        ans.second  =max(leftAns.second , rightAns.second ) + 1; 

        return ans;
        

    }
    int diameterOfBinaryTree(TreeNode* root) {
        if (!root )return 0 ; 
        return solve(root ).first -1 ; // because number of edges are one smaller than actual no of nodes 
    }
};