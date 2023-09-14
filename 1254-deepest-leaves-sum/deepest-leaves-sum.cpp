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
    int deepestLeavesSum(TreeNode* root) {
     
        // maximum sum + level order traversal 
        int maxSum =0 , sum  ; 

        queue<TreeNode* > q ; 
        q.push(root ) ; 

        while (!q.empty()){
           int level = q.size() ; 
            sum =0 ;
           for(int i=0;i<level ; i++){
              
                TreeNode* frontNode = q.front() ; 
            q.pop() ; 

            if (frontNode->left== NULL and frontNode->right == NULL ){
                sum += frontNode->val ;
                
            }

            // work for the childs 

            if (frontNode->left ){
                q.push(frontNode->left ) ; 
            }

            if (frontNode->right ){
                q.push(frontNode->right ) ;
            }
           }


        //    if (sum>maxSum )maxSum = sum ;

           

        }
        return sum ;
        
    }
};