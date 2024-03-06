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
    bool solve(TreeNode* root , int target,vector<int> temp , vector<vector<int>>&ans ){
        if (!root )return false ; 

            if (target == root ->val and (!root ->left and !root ->right ) ){// root must be leaft node for this condition to be true 
                temp.push_back(root->val);
                ans.push_back(temp);
                return true ; 
            }

        // work part 
             temp.push_back(root ->val);

            bool leftAns = solve(root ->left , target - root ->val, temp , ans  ); 
            bool rightAns = solve(root ->right , target - root ->val,temp , ans  );

            if(leftAns || rightAns ){
                return true ; 
            }
            return false;
        

        }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
         vector<vector<int>>ans ; 
         if (!root )return ans;
           vector<int> temp ; 
         solve(root , targetSum , temp , ans );
         return ans;
       
    }
};