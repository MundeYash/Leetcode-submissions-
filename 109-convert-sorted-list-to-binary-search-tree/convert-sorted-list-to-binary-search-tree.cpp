/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
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
    TreeNode* sortedListToBST(ListNode* head) {
        // step 1 : store  the list elements in array 
        vector<int> ans ; 
        while (head){
            ans.push_back(head ->val ) ; 
            head = head ->next ;

        }

        int n = ans.size() ;
        // step 2 : sorted array to bst conversion 
        return sortedArray2BST(ans , 0 , n-1 ) ;

        
    }
};