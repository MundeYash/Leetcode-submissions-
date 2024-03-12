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
            
            map<int ,int> nodes ; // mapping of level number with rightmost node value 
            queue<pair<TreeNode*, int > > q ; 
            q.push(make_pair(root, 0)); 

            while (!q.empty()){
                pair<TreeNode*,int > frontValue = q.front() ; 
                q.pop(); 

                TreeNode* frontNode = frontValue.first ; 
                int level = frontValue.second ; 

                nodes[level] = frontNode->val ;

                if (frontNode->left ){
                    q.push(make_pair(frontNode->left , level + 1));
                }

                if (frontNode->right ){
                    q.push(make_pair(frontNode->right , level + 1  ));
                }
            }

            // after the traversal extract the values from the maps 

            for (auto it: nodes ){
                ans.push_back(it.second );
            }

            // sort(ans.begin() , ans.end());
            return ans;


    }
};