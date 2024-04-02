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

    void  inorder(TreeNode* root , TreeNode* &prev , int &minDiff){
        if (!root ){
            return ; 
        }

        inorder(root->left , prev , minDiff );

        // work 
        if( prev != NULL ){
            int value = abs(prev->val  - root->val);
            minDiff = min(minDiff, value );
        }

        if (root != NULL ){
            prev = root  ; 
        }


        inorder(root->right , prev , minDiff) ;


    }
    int getMinimumDifference(TreeNode* root) {
        //Optimised Code : Time : O(n) , space :O(H)
        int minDiff = INT_MAX ; 
        TreeNode* prev  = NULL ; 

        inorder(root , prev , minDiff); 

        if (minDiff == INT_MAX )return 0 ; 

        return minDiff ;

    }
};