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
// Approach :Recursion , time :o(log n )
    TreeNode* searchBST(TreeNode* root, int key ) {
        if (!root )return NULL;

        // optimised approach: time : O(log n ) , space :O(1) , concept : itertive approach ;

        TreeNode* temp = root ; 

        while (temp ){
            if (temp ->val == key ){
                return temp ;
            }
            else if (temp->val <key ){
                // search in the right part 
                temp = temp->right ;

            }
            else{
                // search in the left part 
                temp = temp->left ;
            }
        }

        // till here node is finded , node does not exists 
        return NULL ;

        
    }
};