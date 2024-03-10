class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        vector<int> ans;
        // step 1: sort both the arrays 
        sort(nums1.begin() ,nums1.end()); 
        sort(nums2.begin() , nums2.end()); 

        int i=0  , j=0 ;
        int n = nums1.size(), m= nums2.size(); 
        while (i<n and j< m ){
            if (nums1[i]== nums2[j]){
                if (!ans.empty()){
                    if (ans.back()!= nums1[i]){
                         ans.push_back(nums1[i]);
                    }
                }
                else{
                 ans.push_back(nums1[i]);
               
                }
                 i++ ; 
                j++ ;

            }
            else if (nums1[i]>nums2[j]){
                j++ ; 
            }
            else{
                i++ ;
            }
        }
        return ans;
    }
};