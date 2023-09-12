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
        // base case 
        if (!root )return ; 
        inorder(root->left , ans ) ; 
        ans.push_back(root ->val ) ;
        inorder (root ->right , ans ) ;
    }
    bool findTarget(TreeNode* root, int k) {
        
        // Store the inorder traverseal and find the two using  : two pointer approach 
        vector<int> ans ;
         inorder(root, ans ) ; 

        // check for the valid pair 
        int n = ans.size();

         int i=0 , j= n-1 ; 

         while (i<j){
             int value = ans[i] + ans[j]  ;
             if (value ==k){
                 return true ; 
             }
             else if (value > k ){
                 j-- ;

             }
             else { 
                 i++ ;

             }
         }
         return false;

    }
};