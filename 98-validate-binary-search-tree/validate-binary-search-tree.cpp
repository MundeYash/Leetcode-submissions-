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

bool check(TreeNode* root , long long  mini  , long long  maxi ){
    // base case    
    if (!root )return true ; 

    if (root ->val > mini and root ->val < maxi ){
        bool leftCheck = check (root->left , mini , root ->val ) ; 

        bool rightCheck = check(root ->right , root ->val , maxi);
        return leftCheck && rightCheck ; 
    }
    else{
        return false;
    }
}
    bool isValidBST(TreeNode* root) {
        // time : O(n) , space : O(1) 

        // concept : range checking and recursion 
        if (!root )return true ; 

        return check(root, LLONG_MIN, LLONG_MAX ) ;// minimum value and maximum value 


    }
};