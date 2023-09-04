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
    int findBottomLeftValue(TreeNode* root) {
        // concept :level order 
        // level order traversal 
        queue<TreeNode* > q; 
        q.push(root ) ; 
        vector<vector<int>> ans ;

         while (!q.empty()){
             int level = q.size();
             vector<int> temp ;
             for (int i=0;i<level ;i++){
                TreeNode* frontNode = q.front() ; 
             q.pop() ;

             temp.push_back(frontNode->val);


             if (frontNode->left ){
                 q.push(frontNode->left ) ;
             }

             if (frontNode->right ){
                 q.push(frontNode->right ) ;
             }
             }
             ans.push_back(temp);

         }

         reverse(ans.begin() , ans.end()) ;
         return ans[0][0];
        
    }
};