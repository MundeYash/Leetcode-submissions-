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

// function for creating the sorted array to bst 
TreeNode*  sortedArray2BST( vector<int> arr , int s , int e ){
    if (s>e )return NULL ;

    int mid = (s+e )/2 ; 

    TreeNode* root = new TreeNode(arr[mid]) ; 
    root ->left = sortedArray2BST(arr , s , mid -1 ) ; 
    root ->right = sortedArray2BST(arr , mid+1 , e) ; 

    return root ;
}
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        int n = nums.size() ;
        return sortedArray2BST(nums , 0  , n-1 );
        
    }
};