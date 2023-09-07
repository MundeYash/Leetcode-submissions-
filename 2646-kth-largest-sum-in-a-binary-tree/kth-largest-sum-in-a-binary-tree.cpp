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
    long long kthLargestLevelSum(TreeNode* root, int k) {
        // concept :Level Order Traversal 

        queue<TreeNode* > q; 
        q.push(root ) ; 

        vector<long long > ans;

       

        while (!q.empty()){
            int level = q.size() ; 
            long long  sum =0 ;

            for (int i=0 ;i< level ;i++)
            {

                TreeNode* frontNode = q.front () ; 
                q.pop() ; 

                sum +=(long long ) frontNode->val ; 

                if (frontNode->left ){
                    q.push(frontNode->left ) ;
                }
                if (frontNode->right ){
                    q.push(frontNode->right );
                }

            }
  
            ans.push_back(sum);
        }

 


        // sort the ans and than the kth largest sum 
        int n = ans.size();
        sort(ans.begin()  ,ans.end());

        if (k>n ){
            return -1 ;
        }
        return ans[n-k];
        
    }
};