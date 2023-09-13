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

// function for deleting a particular / node->data value in the binary search tree 
TreeNode* maxValue (TreeNode* root ){
    if (!root )return NULL ;

    while (root->right){
        root= root->right ;
    }
    return root ;

}




    TreeNode* deleteNode(TreeNode* root, int val) {
        // delete the node whose data is equal to the val 

    if (!root )return root  ; 

    // recursive case 
    if (root ->val == val ){

        // important case , 4 options are there for the deletion 

        // 0 child exits 
        if(root->left == NULL and root ->right == NULL ){
            delete root ; 
            return NULL ;
        }

        // 1child exists (either left or right child )

        if (root->left == NULL and root -> right != NULL ){
            // store the right node 
            TreeNode* temp = root->right  ;
            delete root ; 
            return temp ;
        }

        if (root->left != NULL and root->right == NULL ){
            TreeNode* temp = root->left ; 
            delete root ; 
            return temp ;
        }

        // 2child exits (both left and right ){either find maximum from left subtree and replace it with root  or find minimum element form the right and replace it with root , do recursvive call}

        if (root ->left != NULL and root ->right != NULL ) {
            // int mini = minValue (root ->right )->val ;// gives minimum value from the right 
            // root ->val = mini ; // add min value to the root value 
            // root ->right = deleteNode(root->right , mini);
            // return root ;

            int maxi = maxValue (root ->left )->val ; // give the maximum value from the left subtree 
            root ->val = maxi ; // add max value to the root value 
            root ->left = deleteNode(root->left , maxi ) ;
            return root ;


        }

    }

    else if (root ->val <val ){
        // val exists in right subtree (move to the right )
        root ->right = deleteNode(root->right , val) ; 
        return root ;

    }
    else{
        // val exists in the left subtree (move to the left )
        root ->left = deleteNode(root->left , val);
        return root ;
    }

    return root ;


    }

    void inorder(TreeNode* root , vector<int>&in ){
    if (!root)return ; 
 
    inorder (root ->left , in ) ; 
       in.push_back(root->val ) ; 
    inorder(root->right , in ) ; 
    
}
    TreeNode* trimBST(TreeNode* root, int low, int high) {

    //     vector<int> ans ; 
    //     inorder(root , ans ) ; 

    //     for (int i=0 ;i<ans.size() ; i++){
    //         if (ans[i]<low || ans[i]>high ){
    //             root = deleteNode(root , ans[i]) ; 
    //         }
    //     }
    
    // return root ;
    if (!root) {
        return nullptr;  // Return nullptr for empty tree
    }

    // If the current node's value is outside the range, trim the tree and update root
    if (root->val < low) {
        return trimBST(root->right, low, high);
    } else if (root->val > high) {
        return trimBST(root->left, low, high);
    }

    // Recursively trim the left and right subtrees
    root->left = trimBST(root->left, low, high);
    root->right = trimBST(root->right, low, high);

    return root;
        
    }
};