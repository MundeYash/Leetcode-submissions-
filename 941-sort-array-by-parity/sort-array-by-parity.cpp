class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        // Order Maintain : 2 arrays and sorting 
        vector<int> ans , odd ,even ; 
        int n = nums.size(); 
        for (int i= 0;i<n ;i++ ){
            int value = nums[i]; 
            if (value&1)odd.push_back(value); 
            else even.push_back(value );
        }
        int i=0 , j=0 ; 
       
         while (i<even.size()){
            ans.push_back(even[i++]); 
          
        }
         while ( j<odd.size()){
           
            ans.push_back(odd[j++]);
        }
        return ans;
    }
};