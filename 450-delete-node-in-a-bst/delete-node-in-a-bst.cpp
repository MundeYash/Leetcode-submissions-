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
        TreeNode* findMin(TreeNode* node) {
            while (node->left) {
                node = node->left;
            }
            return node;
        }
    TreeNode* deleteNode(TreeNode* root, int key) {
        if (root == NULL ) {
        return root; // Tree is empty or value not found
    }

    if (key < root->val) {

        // move to the left 
        root->left = deleteNode(root->left, key);
    } else if (key > root->val) {
        // move to right 
        root->right = deleteNode(root->right, key);
    } else {
        // Node with the key value found, delete it


        // Case 1: Node with no child
        if (root ->left == NULL and root ->right == NULL ){
            delete root ; 
            return NULL ;
        }

        // Case 1: Node with only one child or no child
        if (root->left == nullptr) {
            TreeNode* temp = root->right;
            delete root;
            return temp;
        } else if (root->right == nullptr) {
            TreeNode* temp = root->left;
            delete root;
            return temp;
        }

        // Case 2: Node with two children
        TreeNode* temp = findMin(root->right); // Find the inorder successor
        root->val = temp->val; // Copy the successor's data to this node
        root->right = deleteNode(root->right, temp->val); // Delete the successor
    }

    return root;
    }
};