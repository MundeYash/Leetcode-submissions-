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
    bool isEvenOddTree(TreeNode* root) {
        //even level -> all nodes with odd values in decreasing order ,  odd level - > even values with decreasing order 
        // concept : level order traversal + comparison 
        vector<vector<int>> ans ; 

        queue<pair<TreeNode*, int> > q ; 
        q.push(make_pair(root  ,0 )); // node , level no

        while (!q.empty()){
            int n = q.size(); 
            vector<int> temp;
            for (int i=0 ;i<n ;i++ ){
                pair<TreeNode*, int> frontValue = q.front(); 
                q.pop(); 

                TreeNode* frontNode = frontValue.first ; 
                int level = frontValue.second ;
            // important checking even /odd condition 
            bool check = false;
            if  (level %2 ==0 and frontNode->val %2 !=0  ){
               check = true;
            }
            else if ( level %2 !=0 and frontNode->val %2 ==0  ){
                check = true ;
            }
            if (check == false)return false;
                temp.push_back(frontNode->val); 

                if (frontNode->left ){
                    q.push(make_pair(frontNode->left , level +1 )); 

                }

                if (frontNode->right ){
                    q.push(make_pair(frontNode->right , level + 1 ));
                }
            }

            // after completion of level : 
            ans.push_back(temp);
        }

        // strcitly increasing checking 

    for (int i=0 ;i<ans.size();i++ ){

         if (i&1==1){
         
          for (int j=0 ;j<ans[i].size() ;j++ )  {
                    // odd values->decreasing  ;
                    
                    if (ans[i][j] &1 ) return false;
                    if (j== ans[i].size()-1 )continue ;
                        if (ans[i][j+1 ]>= ans[i][j]){
                            return false;
                        }
                }
         }


            else{
                    // even level
                     for (int j=0 ;j<ans[i].size()-1 ;j++ ){

                       if (ans[i][j]&1 ==0 )return false;
                       if (j== ans[i].size()-1 )continue ;
                        // even values->increasing  ;
                        
                        if (ans[i][j+1 ] <= ans[i][j]){
                            return false;
                        
                    }

                }
            }


        }



    return true ; 
        
    
    }
};