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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        bool change = true  ; 
        vector<vector<int>> ans ; 
        if (!root )return ans;
        queue<TreeNode* > q; 
        q.push(root ); 

        while (!q.empty()){
            int n = q.size(); 
            vector<int> temp ; 

            for (int i=0 ;i<n ;i++ ){
                TreeNode* frontNode =q.front() ; 
                q.pop(); 

                temp.push_back(frontNode->val );

                if (frontNode->left ){
                    q.push(frontNode->left );
                }

                if (frontNode->right ){
                    q.push(frontNode->right );
                }
            }

            if (change == false ){
                reverse(temp.begin()  , temp.end()); 
            }
            ans.push_back(temp  ) ; 
            change = !change ; 
        }

        return ans;
        
    }
};