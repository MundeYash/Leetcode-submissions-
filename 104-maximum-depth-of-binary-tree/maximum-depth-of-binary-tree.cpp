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
    int maxDepth(TreeNode* root) {
        //Brute force Approach : O(n) , space : O(n) (iterative approach , level order traversal )
        // concept : find the maximum level number 
        if(!root )return 0 ;
        queue<TreeNode* > q ; 
        q.push(root ); 
    int ans =0 , levelNo=1;
        while (!q.empty()){
            int n = q.size(); 

            for (int i= 0;i<n ;i++ ){
                TreeNode* frontNode = q.front(); 
                q.pop(); 

                if (frontNode->left){
                    q.push(frontNode->left );
                }

                if (frontNode->right ){
                    q.push(frontNode->right );
                }


            }
            if (levelNo>ans)ans = levelNo;
            levelNo++ ;
        }
        return ans;
    }
};