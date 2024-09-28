class Solution {
public:
    int numTriplets(vector<int>& nums1, vector<int>& nums2) {
     // brute force 
     int n = nums1.size();
     int m = nums2.size();
     int count =0 ; 
     for (int i=0 ;i<n ;i++ ){

        for (int j=0 ;j<m ;j++ ){
            for (int k=j+1;k<m ;k++){
                // check condition 
                long long value1 = (long long )nums1[i] * (long long )nums1[i];
                long long value2 = (nums2[j] *(long long ) nums2[k]);
                if (value1 == value2 ){
                    count ++ ; 
                }
            }
        }
     }   

    // find the triplets from second method 
     for (int i=0 ;i<m ;i++ ){

        for (int j=0 ;j<n ;j++ ){
            for (int k=j+1;k<n ;k++){
                // check condition 
                long long value1 = (long long )nums2[i] *(long long ) nums2[i];
                long long value2 = (nums1[j] *(long long ) nums1[k]);
                if (value1 == value2 ){
                    count ++ ; 
                }
            }
        }
     }   
     return count ; 
    }
};