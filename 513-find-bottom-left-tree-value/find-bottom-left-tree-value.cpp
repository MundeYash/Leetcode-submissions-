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
        // highest or last  level leftmost value 

 
        if (!root )return -1 ; 

        //level order traverasl format 

        queue<TreeNode*> q; 
        q.push(root ); 
        int sol=-1 ;

        while (!q.empty()){
            int n = q.size(); 
            
            for (int i=0 ;i<n ;i++){
                TreeNode* frontNode = q.front(); 
                q.pop(); 
              
                sol = frontNode->val;


                 if (frontNode->right ){
                    q.push(frontNode->right );
                }
                if (frontNode->left ){
                    q.push(frontNode->left );
                }

               
            }

           
            
        }

        return sol;



    }
};