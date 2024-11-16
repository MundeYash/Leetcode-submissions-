class Solution {
public:
    int solve(vector<int> arr , int index , int  k ){
    
        int maxi = arr[index];
  
        for (int i= index+1  ;i<(index + k) ; i++ ){
            if(arr[i] != (arr[i-1 ] + 1 ) )return -1; 
            if (arr[i]>maxi )maxi = arr[i];
        }

        return maxi;

    }
    vector<int> resultsArray(vector<int>& nums, int k) {
        //applying brute force approach: 
        int n = nums.size() ; 
        vector<int> ans (n-k+1 ,-1);


        for (int i=0;i<=n-k ;i++ ){
            int value =  solve(nums ,i, k) ; 
            cout<<value <<endl;
            ans[i] = value ;
         

        }

        return ans;
        
    }
};