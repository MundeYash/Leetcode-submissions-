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

    void inorder (TreeNode* root  ,vector<int>&ans ){
        // baase case 
        if (!root )return ; 
        // left check 
        inorder (root ->left , ans ) ; 
        // store the ans 
        ans.push_back(root->val  ) ; 
        inorder (root ->right , ans ) ;
    }
    bool isValidBST(TreeNode* root) {
        if (!root )return true ;
        // aproach : inroder traversal + sorted check 
        // time : O(n) + O(n) , space : O(n)

        vector<int> ans ; 
        inorder (root , ans  ) ; 

        // step2 : check whether the inorder traversal is sorted or not 
        int n = ans.size() ;
        for (int i=0 ;i<n-1 ;i++ ){
            if (ans[i]>= ans[i+1]){
                return false ;
            }
        }
        return true ;
        
    }
};