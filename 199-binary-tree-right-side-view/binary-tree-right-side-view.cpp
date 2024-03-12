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
    vector<int> rightSideView(TreeNode* root) {
            vector<int> ans ; 

            if (!root )return ans; 
            
           
           queue<TreeNode*> q; 
           q.push(root ); 

           while(!q.empty()){
                int  n = q.size(); 
                int value = INT_MIN ;
                for (int i=0 ;i<n ;i++ ){
                    TreeNode* frontNode = q.front(); 
                    q.pop(); 

                    value = frontNode->val;

                    if (frontNode->left ){
                        q.push(frontNode->left );
                    }

                    if (frontNode->right ){
                        q.push(frontNode->right );
                    }
                }

                if(value != INT_MIN){
                    ans.push_back(value );
                }

            
           }

            // sort(ans.begin() , ans.end());
            return ans;


    }
};