class Solution {
public:
    int solvePos(vector<int> arr, int index  , int k ){
        int end = (index+k);
        int ans =0 ; 
        int n = arr.size();

        if (end<=n-1 ){
        for (int i= index+ 1;i<=end ;i++ ){
            ans += arr[i] ;
        }
        }
        else {
            for (int i=index + 1;i<n ;i++ ){
                ans += arr[i] ;
                k-- ;
            }
            for (int i=0 ;i<k ;i++ ){
                ans += arr[i];
            }
        }


        return ans ;

    }


     int solveNeg(vector<int> arr, int index  , int k ){
        k = k*-1;
        int end = (index-k);
        int ans =0 ; 
        int n = arr.size();

        if (end>=0 ){
        for (int i= index- 1;i>=end ;i--){
            ans += arr[i] ;
        }
        }
        else {
            for (int i=index -1 ;i>=0 ;i--){
                ans += arr[i] ;
                k-- ;
            }
            for (int i=n-1 ;i>=n-k ;i-- ){
                ans += arr[i];
            }
        }


        return ans ;

    }
    vector<int> decrypt(vector<int>& code, int k) {
        // concept : prefix sum concept will be used 
        int n = code.size();
        vector<int> ans(n,0) ; 
        vector<int> p(n);
        if (k==0 )return ans;
        if (k>  0 ){
            // postiive value of k 
            for (int i=0 ;i<n ;i++ ){
            int value = solvePos(code, i,k ) ;
            ans[i] = value ; 
            }
        }

        else {
            // negative value of k 
              for (int i=0 ;i<n ;i++ ){
            int value = solveNeg(code, i,k ) ;
            ans[i] = value ; 
            }

        }
        return ans;
        
        


    }
};