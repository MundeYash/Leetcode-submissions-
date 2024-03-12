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
    int sumOfLeftLeaves(TreeNode* root) {
        int ans =0 ; 
        if (!root )return ans; 
        
        // concept : level order traversal 
        
        queue<pair<TreeNode*, bool >> q; 
        q.push(make_pair(root , false )); 
        
        while (!q.empty()){
           
           pair<TreeNode*  , bool > frontValue = q.front() ; 
           q.pop(); 
           
           TreeNode* frontNode = frontValue.first ; 
           bool check = frontValue.second ; 
           
           if (check == true and (frontNode->left== NULL and frontNode->right == NULL )){
               ans += frontNode->val ;
           }
           
           
           if(frontNode->left ){
               q.push(make_pair(frontNode->left , true )); 
           }
           
           if (frontNode->right ){
               q.push(make_pair(frontNode->right , false ));
           }
        }
        
        return ans;
    }
};