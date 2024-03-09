class Solution {
public:
    int getCommon(vector<int>& nums1, vector<int>& nums2) {
        // two pointers approach ; 
        int n  =nums1.size() ;
        int m = nums2.size(); 

        int i=0 , j=0 ; 
        while (i<n and j<m ){
            int val1 = nums1[i]; 
            int val2 = nums2[j]; 

            if (val1== val2){
                return val1;
            }
            else if (val1>val2){
                j++;
            }
            else if (val2>val1 ){
                i++ ; 
            }

            
        }

        return -1 ;
    }
};