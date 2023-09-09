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
void inOrder (TreeNode* root , vector<int> &ans ){
    if (!root ){
        return ;
    }
    inOrder(root ->left ,ans ) ; 
    ans.push_back(root ->val ) ; 
    inOrder (root ->right  , ans ) ;
   
}

    vector<int> findMode(TreeNode* root) {

         vector<int> ans ; 
         inOrder(root , ans ) ; 
         unordered_map<int , int > hash ; 

         for (int i=0 ;i<ans.size() ; i++){
             hash[ans[i]] ++ ;
             
         }
         int maxi = 0 ;
         int maxElement ;

         for (auto it : hash ){

             if (it.second > maxi ){
                 maxi = it.second ; 
                 maxElement = it.first ; 
             }
             
         }
         vector<int> sol ; 
         for (auto it : hash ){
             if (it.second == maxi ){
                 sol.push_back(it.first );
             }
         }
         return sol;
        
    }
};