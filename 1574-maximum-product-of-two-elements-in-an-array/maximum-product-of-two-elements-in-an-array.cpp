class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size() ; 
        int ans =1 ;

        for (int i=0 ;i< n;i++){

            for (int j=0 ;j<n ;j++){
                if (i!=j ){
                    int value = (nums[i]-1 )* (nums[j]-1);

                    if (value >ans ){
                        ans = value ;
                    }

                }
            }
        }

        if (ans ==1 )return 0 ; 
        return ans ;
        
    }
};