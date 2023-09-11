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
    int solve(TreeNode* root , int &k ){
        if (!root )return -1 ; 

        // move in the left to get smaller value 
      int leftCheck =   solve(root ->left , k) ; 
      if (leftCheck != -1)return leftCheck ; 

      k-- ; 
      if (k==0 ){
          return root ->val ;
      }
      return solve(root ->right , k );
    }
    int kthSmallest(TreeNode* root, int k) {
        // concept : counter method + comparison , time : O(log n ) , space  :O(n) recursive stack space 

        if (!root )return -1 ; 
        return solve(root , k ) ;
        
    }
};