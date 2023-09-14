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
    int sumEvenGrandparent(TreeNode* root) {
        int sum =0 ; 

        // concept : level order traversal 
        queue<TreeNode*>q ; 
        q.push(root ) ;

        while (!q.empty()){
            TreeNode* frontNode = q.front() ; 
            q.pop() ; 

            // possible 4 cases 
             // Check if frontNode has a left child and if that left child has left and right children
        if (frontNode->left && frontNode->left->left) {
            if (frontNode->val % 2 == 0) {
                sum += frontNode->left->left->val;
            }
        }

        if (frontNode->left && frontNode->left->right) {
            if (frontNode->val % 2 == 0) {
                sum += frontNode->left->right->val;
            }
        }

        // Check if frontNode has a right child and if that right child has left and right children
        if (frontNode->right && frontNode->right->left) {
            if (frontNode->val % 2 == 0) {
                sum += frontNode->right->left->val;
            }
        }

        if (frontNode->right && frontNode->right->right) {
            if (frontNode->val % 2 == 0) {
                sum += frontNode->right->right->val;
            }
        }
            // work for the child 
            if(frontNode->left ){
                q.push(frontNode->left ) ;

            }

            if (frontNode->right ){
                q.push(frontNode->right );
            }
        }

        return sum ;

        
    }
};