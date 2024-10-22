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
 bool comp(long long a, long long b ){
    if (a>=b)return true ;
    return false;
 }
class Solution {
public:
    long long kthLargestLevelSum(TreeNode* root, int k) {
        // level sum store and sorting for kth largest value 
        long long ans =0 ; 
        queue<TreeNode*> q; 
        q.push(root ) ; 
        vector<long long >temp ; 
        while (!q.empty()){
            int n = q.size() ; 
            long long sum =0 ; 
            for (int i=0 ;i<n ;i++ ){
                TreeNode* frontNode = q.front() ; 
                q.pop();
                sum += frontNode->val ; 

                if (frontNode->left ){
                    q.push(frontNode->left );
                }

                if (frontNode->right ){
                    q.push(frontNode->right);
                }
            }
            // this means completion of one level 
            temp.push_back(sum );
        }
        sort(temp.begin(),temp.end(),comp);
  
        if (temp.size()<k)return -1 ; 
        return temp[k-1];
    }
};