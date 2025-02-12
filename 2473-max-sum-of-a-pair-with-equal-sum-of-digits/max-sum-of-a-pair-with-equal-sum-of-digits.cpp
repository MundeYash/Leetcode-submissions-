class Solution {
public:
    int digitSum(int n ){
        int sum =0 ; 
        while (n){
            sum += (n%10);
            n  = n/10 ;
        }
        return sum;
    }
    int maximumSum(vector<int>& nums) {
        // map based solution 
        int n = nums.size() ; 
        unordered_map<int , vector<int>> mp ; 
        for (int i=0 ;i<n ;i++ ){
            int number = nums[i];
            int sum = digitSum(number);
            mp[sum].push_back(number);

        }
        int ans =INT_MIN;

        for (auto it:mp){
            int n = it.second.size();
            if (n>1){
             sort(it.second.begin(), it.second.end());
             int value = it.second[n-2] + it.second[n-1];
             ans = max(value, ans);
            }

        }
        if (ans == INT_MIN) ans =-1;
        return ans;
        
    }
};