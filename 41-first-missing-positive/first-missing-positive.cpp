class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {

        // Brute force approach : 
        int n = nums.size();
       
        // step 1 : sorting the values 
        // sort(nums.begin() , nums.end());
        int mini = INT_MAX ; 
        int maxi = INT_MIN;
       unordered_map<int , int> freq ;
        // step1  : find the minimum and maximum element 
        for (int i=0 ;i<n ; i++ ){
            freq[nums[i]]++ ;
            if (nums[i]<mini)mini = nums[i]; 
            if (nums[i]>maxi )maxi = nums[i];

        }

        for (int i=1 ;i<=maxi;i++ ){
            if (freq.find(i)== freq.end()){
                // means value not finded in the map 
                return i  ; 
            }
        }

        if (mini <0 and maxi <0 ) return 1 ;

        return maxi + 1;
    }
};