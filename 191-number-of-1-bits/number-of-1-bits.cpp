class Solution {
public:
    int hammingWeight(int n) {
        // counting the set bit only 
        int count =0 ;
        while (n){
            if (n&1){
                count ++ ;
            }
            n = n>> 1;
        }
        return count ; 
    }
};