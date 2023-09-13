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
    int getMinimumDifference(TreeNode* root) {
        vector<int> ans ; 

        int mini = INT_MAX ;
        inorder(root , ans ); 

        for (int i=0 ;i<ans.size() ; i++){
            for (int j=i+1 ;j<ans.size();j++){
                int value = abs(ans[j] - ans[i]) ; 
                if (value < mini ){
                    mini = value ; 
                }
            }
        } 

       
        return mini ;
    }
};