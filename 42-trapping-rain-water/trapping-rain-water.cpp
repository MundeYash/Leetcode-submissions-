class Solution {
public:
    int trap(vector<int>& a) {
        int n = a.size(); 
        int   ans =0 ;
        
           // time : O(3N) , space :O(n);
          vector<int>prefix(n,0); 
          prefix[0] = a[0] ; 
          for (int i=1 ;i<n ;i++){
              prefix[i] = max(prefix[i-1], a[i]);
          }

          
          vector<int>suffix(n,0); 
          suffix[n- 1] = a[n-1]; 
          for (int i= n- 2;i>=0 ;i--){
              suffix[i] = max(suffix[i+1] , a[i]);
          }

          for (int i=0 ;i<n ;i++){
              ans = ans +  (min(prefix[i] , suffix[i])) -a[i]; 
          }



        return ans ;
        
    }
};