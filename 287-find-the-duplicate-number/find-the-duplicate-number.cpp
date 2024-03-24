class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        
         int n = nums.size(); 
        int N = n-1;
        vector<int> freq(N+1,0); 
       

        for (int i=0 ;i<n ;i++ ){
            int index = nums[i];
            freq[index]++;
        }

        for (int i=1;i<=N ;i++ ){

            if (freq[i]>=2 )return i;
        }
        return -1;
        
    }
};