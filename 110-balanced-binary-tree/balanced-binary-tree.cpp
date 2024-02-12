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

    // // Brute Force Approach : O(n^2) :because of finding the height for each and then checking its balanced or not 
    // int height (TreeNode* root ){
    //     if (!root )return 0 ; 
    //     return max ( height(root->left ), height(root->right) ) + 1 ;
    // }


    // OPTIMISED APPROACH : Time : O(n) ,space: O(n)-> recursive Stack Space 
    pair<bool , int> fastIsBalanced(TreeNode* root ){
         pair<bool , int> ans ; 
         if (!root ){
             ans.first = true ; 
             ans.second = 0 ; 
             return ans;
         }

          pair<bool , int> leftAns = fastIsBalanced (root->left ) ; 
           pair<bool , int> rightAns = fastIsBalanced(root ->right ) ; 

          if (leftAns.first and rightAns.first and abs(leftAns.second - rightAns.second)<=1 ){
              ans.first  = true ; 
          } 
          else{
              ans.first  = false;
          }
          ans.second = max(leftAns.second , rightAns.second )  + 1; 
          return ans;
    }
    bool isBalanced(TreeNode* root) {
        // base case 
        if (!root )return true ; 
        // // work 
        // bool leftAns  = isBalanced(root ->left ) ; 
        // bool rightAns = isBalanced(root ->right ); 
        // int leftHeight = height(root ->left ) ; 
        // int rightHeight = height (root ->right ) ; 
        // if (leftAns and rightAns and abs(leftHeight - rightHeight )<=1 ){
        //     return true ; 
        // }
        // else{
        //     return false;
        // }

         return fastIsBalanced(root ).first ; 

        
    }
};