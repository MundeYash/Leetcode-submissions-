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
void inorder(TreeNode* root , vector<int>&ans ){
    if (!root )return  ; 

    // recursive case 
    inorder (root->left , ans ) ; 
    ans.push_back(root ->val  ) ; 
    inorder(root ->right , ans  ) ;
    return ;
}
    int kthSmallest(TreeNode* root, int k) {
        // concept  : store the inorder and return kth largest element 
        vector<int> ans ; 
        inorder (root , ans ) ;
        return ans[k-1];

        
    }
};