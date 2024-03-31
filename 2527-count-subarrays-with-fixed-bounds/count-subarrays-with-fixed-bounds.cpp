class Solution {
public:
    long long countSubarrays(vector<int>& nums, int minK, int maxK) {
        long long int count =0 ; 
        int n = nums.size();
        int minI =-1 ,maxI =- 1 , badI =-1 ; 


        for (int i=0 ;i<n ;i++ ){
            if (nums[i]<minK|| nums[i]>maxK)badI=i;

            if (nums[i]==minK)minI =i ; 
            if (nums[i]==maxK)maxI = i ; 

            count += max(0 , min(minI,maxI)-badI);
        }

        return count ;
    }
};