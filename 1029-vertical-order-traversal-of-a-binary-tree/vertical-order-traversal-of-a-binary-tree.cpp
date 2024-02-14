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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        // concept : Level Order Traversal and Ordered map (mapping nodes with horizontal distances )
        // Assume Number line and mapping with horizotal distances for each node level wise 
         vector<vector<int>> ans ; 
         if (!root )return  ans ; 

         map<int , map<int , vector<int> > > nodes ; // format map<hd , map<level , vector<int>> > nodes 

         // creation of queues and work for it 
         queue<pair<TreeNode* , pair<int , int> > > q ; // format queue<pair<node*  , pair<hd , level> > > q 
         q.push(make_pair(root , make_pair(0,0)));

         while (!q.empty()){

             int n = q.size(); 

             for (int i=0 ;i<n ;i++ ){
                 pair<TreeNode* , pair<int , int> > frontValue = q.front() ;
                 q.pop(); 
                 TreeNode* frontNode = frontValue.first ; 
                 int hd = frontValue.second.first ; 
                 int lvl = frontValue.second.second ; 

                 // work (mapping)
                 nodes[hd][lvl].push_back(frontNode->val );

                 // work for the child nodes 

                 if (frontNode->left ){// hd decreases in left side 
                     q.push(make_pair(frontNode->left , make_pair(hd-1 , lvl+1 )));
                 }

                  if (frontNode->right ){// because hd increases in right side 
                     q.push(make_pair(frontNode->right , make_pair(hd+1 , lvl+1 )));
                 }


             }
         }


         // pushing values to the answer 

         for (auto i: nodes ){
             vector<int> temp ;
             for(auto j: i.second){
                 // sort to get in increasing order of level 
                 sort(j.second.begin(), j.second.end()); 
                 for (auto k : j.second ){
                     temp.push_back(k);
                 }
             }
             ans.push_back(temp);
         }

         return ans ; 
        
    }
};