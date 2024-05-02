class Solution {
public:
    int findMaxK(vector<int>& nums) {
        int n = nums.size();
        // map based approach 
        unordered_map<int , int  > mp  ; 
        for (int i=0;i<n ;i++ ){
            int value = nums[i]; 
           mp[nums[i]] ++ ;
        }
        int maxi = -1; 
        for (auto it: mp ){
            if(it.first >0 && mp.find(-1 * it.first )!= mp.end() && it.first> maxi){
                // means positive value 
                    maxi  = it.first;

            }
        }
        return maxi;
    }
};