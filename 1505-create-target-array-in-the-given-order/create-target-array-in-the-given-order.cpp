class Solution {
public:
    vector<int> createTargetArray(vector<int>& nums, vector<int>& index) {
        int n = nums.size();
        int i=0 ;
        vector<int>target; 
        while (n--){
            target.insert(target.begin() + index[i], nums[i]);
            i++ ;
        }
        return target;

    }
};