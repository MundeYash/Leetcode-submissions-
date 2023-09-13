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
    void inorder(TreeNode* root , vector<int>&in ){
    if (!root)return ; 
 
    inorder (root ->left , in ) ; 
       in.push_back(root->val ) ; 
    inorder(root->right , in ) ; 
    
}
    TreeNode* increasingBST(TreeNode* root) {
        
        // binary search tree to the sorted list 
        vector<int> ans ; 
        inorder(root , ans ) ; 

        TreeNode* dummy = new TreeNode(0) ; 
        TreeNode* temp = dummy ; 

        for (int i=0 ;i<ans.size() ; i++){
            TreeNode* newNode = new TreeNode(ans[i]) ; 
            temp ->right = newNode ; 
            temp = temp->right ; 
        }
        return dummy->right ;


    }
};