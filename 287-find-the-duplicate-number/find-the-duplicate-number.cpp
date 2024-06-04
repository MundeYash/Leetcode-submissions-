class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int n = nums.size(); 
        vector<int> update(n-1, 0); 
        for(int i= 0 ;i<n;i++ ){
            if (update[nums[i]-1] == 1){
                return nums[i];

            }
            else{
                update[nums[i]-1] =1 ;
            }
        }

        return -1;
    }
};