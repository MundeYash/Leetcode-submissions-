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
    int  findLevelNodes (TreeNode* root ,   unordered_map<int , vector<pair<int,int  > > >  &mp ){
        // level order traversal 
        queue<pair<TreeNode* , TreeNode*>> q; 
        q.push({root,root  }) ; //child , parent  
        int lvl =0 ;
        while (!q.empty()){
            int n = q.size() ; 
            for (int i=0 ;i<n ;i++ ){
                pair<TreeNode* , TreeNode*> frontValue = q.front();
                TreeNode* frontNode = frontValue.first; 
                TreeNode* parentNode = frontValue.second ; 
                q.pop() ; 
                mp[lvl].push_back({frontNode->val , parentNode->val }); 


                if (frontNode->left ){
                    q.push({frontNode->left ,frontNode}) ;
                }

                if (frontNode->right ){
                    q.push({frontNode->right, frontNode} );
                }
            }   
            lvl ++ ; 
        }

        // just sort everything 
         for (int i=0 ;i<lvl;i++ ){
            sort(mp[i].begin(),mp[i].end());
          
        }
       
        return lvl ;
    }
    void printMap (  unordered_map<int , vector<pair<int,int > > >  mp ){
        for (auto it: mp ){
            for (auto i : it.second ){
                cout<<i.first<<", "<<i.second<<"| ";
            }
            cout<<endl;
        }
        cout<<endl<<endl;
    }
    bool flipEquiv(TreeNode* root1, TreeNode* root2) {
        if (!root1 && !root2 )return true ; 
        if (!root1 || !root2 )return false ;
        // map based approach and Level order traversal + parent factor consideration 

        unordered_map<int , vector<pair<int,int > > > First   ;
          unordered_map<int , vector<pair<int ,int> > > Second ;
       int lvl1 =  findLevelNodes(root1, First );
       cout<<"level is : "<<lvl1<<endl ; 
       printMap(First);
        
       int lvl2 =  findLevelNodes(root2, Second );
       cout<<"level is : "<<lvl2<<endl ; 
       printMap(Second);

        // comparions 
        if (lvl1 != lvl2 )return false; 
          for (int i=0 ;i<lvl1;i++ ){
            
            int n = First[i].size() ; 
            int m = Second[i].size() ;
            if (n!=m ) return false;

            for (int j=0 ;j<n ;j++ ){
                if (First[i][j].first != Second[i][j].first  || (First[i][j].second != Second[i][j].second ))return false ;
            }
            
          
        }
       
        return true ;



    }
};