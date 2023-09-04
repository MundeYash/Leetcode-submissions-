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

void morris(TreeNode* root , vector<int>&ans ){
    if (!root )return ; 

    // two pointers are need 
    TreeNode* pre , *curr ; 
    curr = root ; 

    while (curr != NULL ){
        if (curr->left == NULL ){
            ans.push_back(curr->val ) ; 
            curr = curr ->right ; 
        }
        else{
            pre = curr ->left ; 
            while(pre->right != NULL and pre->right!= curr ){
                pre = pre ->right ; 
            }


            if (pre->right == NULL ){
                pre->right = curr ;
                curr = curr->left;

            }
            else{
                pre->right = NULL ;
                ans.push_back(curr->val);
                curr = curr->right ;
            }

        }

    }
}
    vector<int> inorderTraversal(TreeNode* root) {
        // inorder traversal printing using the O(n) time and constant space O(1)
        // concept Used Morris Traversal 
        vector<int>  ans ; 
        if (!root )return ans;

        morris(root , ans ) ; 
        return ans ;


        
    }
};