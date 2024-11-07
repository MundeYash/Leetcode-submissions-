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
    void solve(TreeNode* root , string path , vector<string>&ans ){
        // base case 
        if (!root )return ; 
        path.push_back(root->val +'a');

        if (root->left == NULL && root->right == NULL ){
            // leaf node case 
         
            reverse(path.begin(),path.end());
               ans.push_back(path);
            return ;
        }

        if (root->left != NULL ){
            solve(root->left , path, ans ) ; 

        }
        if (root ->right != NULL ){
            solve(root->right , path , ans ) ;
        }
    }
    string smallestFromLeaf(TreeNode* root) {
        // root to leaf path and string concept 
        string ans ="" ;
        vector<string> output  ; 
        string path ="" ; 
        solve(root , path , output ) ; 

        sort(output.begin(),output.end()) ; 

        for (int i=0 ;i<output.size();i++ ) {cout<<output[i]<<",";}
        if (output.size()==0 )return ans; 
        // reverse(output[0].begin(),output[0].end()) ;
        return output[0] ; 

        
    }
};