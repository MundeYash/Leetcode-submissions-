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
    int rangeSumBST(TreeNode* root, int low, int high) {
        int sum =0 ;
        vector<int> in ; 
        inorder(root , in ) ; 
        for (int i=0 ;i<in.size() ; i++){
            if (in[i]>=low and in[i]<=high ){
                sum += in[i];
            }
        }
        return sum ;
        
    }
};