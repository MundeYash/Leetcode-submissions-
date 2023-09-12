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

    TreeNode* solve(vector<int> pre , int mini, int maxi , int &index ){
        // base case 
        if (index >= pre.size()) return NULL ;

        if (pre[index]<mini || pre[index]>maxi )return NULL ; 

        // create root 
        TreeNode* root = new TreeNode(pre[index++]) ; 
        root ->left = solve(pre , mini , root->val , index ) ; 
        root ->right = solve(pre , root->val , maxi , index  ) ; 
        

        return root ;
    }

    TreeNode* bstFromPreorder(vector<int>& pre) {
        
        int n = pre.size() ; 
        int index =0 ;
        return solve(pre , INT_MIN , INT_MAX ,  index ) ;




    }
};