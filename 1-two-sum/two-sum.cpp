class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        // time :O(n^2 ) , space : O(N) // for the hashing array 
        int n  = nums.size() ;
        vector <int> ans ; 
        map<int, int >mpp ; 
        for (int i=0 ;i<n ;i++){
            int num = nums[i] ; 
            int moreValue= target- num ; 
            // finding it's presence in the hash 
            if (mpp.find(moreValue)!= mpp.end()){
                // return the indexes of the pair 
                return{mpp[moreValue]  , i } ;
            }
            mpp[num]= i ;
        }
         return ans ; 
        
    }
};