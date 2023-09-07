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
    int maxLevelSum(TreeNode* root) {
        // concept : Level Order Traversal 

        queue<TreeNode* > q; 
        q.push(root ) ; 
        vector<int> ans ; 

        while (!q.empty()){
            int level = q.size() ; 
            int sum =0 ;

            for (int i=0 ;i<level ;i++){

                TreeNode* frontNode = q.front ( ) ; 
                q.pop() ; 
                sum += frontNode->val ; 

                if (frontNode-> left ){
                    q.push(frontNode->left ) ;
                }

                if (frontNode->right ){
                    q.push(frontNode->right ) ;
                }

            }
            ans .push_back(sum) ;
        }

        // iterating from the  last 
        int n = ans.size() ; 

        int minLevel=-1 ; 
        int maxSum = INT_MIN ;


        for (int i=n-1 ;i>=0 ;i--){

            if ( ans[i]>= maxSum ){
                maxSum = ans[i] ; 
                minLevel = i ;
            }

        }
        return minLevel + 1;
        
    }
};