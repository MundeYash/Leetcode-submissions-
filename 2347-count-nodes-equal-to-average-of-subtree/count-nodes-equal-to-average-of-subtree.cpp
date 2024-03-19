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
     pair<int , int> solve(TreeNode* root , int &count  ){
           pair<int , int> ans;
        if(!root ){
            ans.first = 0 ; 
            ans.second = 0 ; 
            return ans;

        }


        // leaf node case 
        if (!root->left and!root ->right ){
            ans.first = root->val;
            ans.second = 1 ; 
        }


           pair<int , int> leftAns = solve(root ->left , count ); 
            pair<int , int>  rightAns = solve(root ->right,count ); 

            // work 

            ans.first = (leftAns.first + rightAns.first + root->val); 
            ans.second = (leftAns.second + rightAns.second + 1 ); 
            // importnat condition check 
            if ((ans.first/ans.second )== root->val )count ++ ;
            return ans;

     }
    int averageOfSubtree(TreeNode* root) {
        // simple traversal format : post order traversal (left , right , node )
        if (!root )return 0 ; 
        int count =0 ; 
        solve(root , count ); 
        return count ;
    }
};