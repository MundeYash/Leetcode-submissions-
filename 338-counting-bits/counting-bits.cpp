class Solution {
public:
    int countSetBit(int number ){
        int count =0 ; 
        while (number ){
            if (number&1 ){
                count ++ ;
            }
            number = number >> 1;
        }
        return count ;
    }
    vector<int> countBits(int n) {
        vector<int> ans (n+1);
        ans[0]=0;
        for (int i=1;i<=n ;i++ ){
            ans[i] = countSetBit(i);


        }
        return ans;
    }
};