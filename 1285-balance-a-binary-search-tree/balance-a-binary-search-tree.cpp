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
void inorder(TreeNode* root , vector<int> &ans ){
    if(!root )return ; 
    inorder(root->left , ans ) ; 
    ans.push_back(root ->val ) ; 
    inorder (root ->right , ans ) ; 
    

}

// function for creating the sorted array to bst 
TreeNode*  sortedArray2BST( vector<int> arr , int s , int e ){
    if (s>e )return NULL ;

    int mid = (s+e )/2 ; 

    TreeNode* root = new TreeNode(arr[mid]) ; 
    root ->left = sortedArray2BST(arr , s , mid -1 ) ; 
    root ->right = sortedArray2BST(arr , mid+1 , e) ; 

    return root ;
}

    TreeNode* balanceBST(TreeNode* root) {
        if (!root )return NULL ;

        // step 1 find the inorder traversal 
        vector<int> ans ; 
        inorder (root , ans ) ;

        // Step 2 sorted array to bst creation 
        return  sortedArray2BST(ans , 0 , ans.size()-1) ;
        
        
    }
};