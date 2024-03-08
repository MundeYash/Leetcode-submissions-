class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        // concept : unordered Map and frequecny finding 
        int n = nums.size(); 

        unordered_map<int , int > mp  ;
          int maxFreq=0 ; 

        for (int i=0 ;i<n ;i++ ){
           if(mp.find(nums[i])!= mp.end()){
                mp[nums[i]] +=1  ; 
                maxFreq = max(maxFreq, mp[nums[i]]);
           }
           else{
               mp[nums[i]] =1 ;
                maxFreq = max(maxFreq, mp[nums[i]]);
           }
        }
        int ans = 0 ;

        for (auto it: mp ){
            if (it.second == maxFreq){
                ans += it.second ;
            }
        }
        return ans;



      

        
    }
};