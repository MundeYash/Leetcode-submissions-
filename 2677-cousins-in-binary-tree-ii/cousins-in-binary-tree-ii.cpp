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
    TreeNode* replaceValueInTree(TreeNode* root) {
        // concept : Mapping level no and parent of each node
        if (!root|| (!root->left && !root->right ))return root ; 
        unordered_map<int , vector<pair< pair<TreeNode* , int>, TreeNode*>>> mp ; //levelNo -> ((nodevalue, nodevalue) , parent )
        queue<pair<TreeNode*,TreeNode*>> q; 
        q.push({root , root });
        int lvl = 0 ;

        while (!q.empty()){
            int n = q.size() ; 
            for (int i=0 ;i<n ;i++ ){
                pair<TreeNode* , TreeNode*> frontValue = q.front() ; 
                q.pop();
                TreeNode* frontNode = frontValue.first  ;
                int frontNodeValue = frontNode->val;
                TreeNode* parentNode = frontValue.second ; 

                mp[lvl].push_back({{frontNode, frontNodeValue} , parentNode});

                if (frontNode->left ){
                    q.push({frontNode->left , frontNode});
                }
                if (frontNode->right ){
                    q.push({frontNode->right , frontNode});
                }
            }
            // completion of one level 
            lvl ++ ;
        }


        // main work 
         q.push({root , root });
         lvl =0 ;
        while (!q.empty()){
             int n = q.size() ; 
            for (int i=0 ;i<n ;i++ ){
                pair<TreeNode*, TreeNode*> frontValue = q.front() ; 
                q.pop();
                TreeNode* frontNode = frontValue.first  ;
                int frontNodeValue = frontValue.first->val ;
                TreeNode* parentNode = frontValue.second ; 

               int sum =0 ; 
               for (auto i: mp[lvl]){
                    if (i.second != parentNode ) sum += i.first.second ;
               }

             

                if (frontNode->left ){
                    q.push({frontNode->left , frontNode});
                }
                if (frontNode->right ){
                    q.push({frontNode->right , frontNode});
                }
                  frontNode->val = sum ; 
            }
            // completion of one level 
            lvl ++ ;
        }
        return root ;
    }
};