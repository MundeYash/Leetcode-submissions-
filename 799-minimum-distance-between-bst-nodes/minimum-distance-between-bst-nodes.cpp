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
     void  inorder(TreeNode* root , vector<int>&ans ){
         if (!root )return ; 
         inorder(root->left , ans ) ; 
         ans.push_back(root ->val ) ; 
         inorder(root ->right , ans ) ; 
         return ; 
     }
    int minDiffInBST(TreeNode* root) {
        // store the inorder traversal and find the abs min diff 
        int minDiff = INT_MAX  ; 
        vector<int> in ; 
        inorder(root , in ) ; 

        for (int i=0 ;i<in.size() ; i++){
            for (int j=i+1 ;j<in.size() ;j ++){
                int value = abs(in[j]-in[i]); 
                minDiff = min(minDiff , value ) ;
            }
        }
        return minDiff ;

        
    }
};