class Solution {
public:
int generateSum (int s ,int e ){
    int sum=0 ; 
    for (int i=s ;i<= e;i++ ){
        sum += i ;
    }
    return sum ;
}
    int pivotInteger(int n) {
        // brute force solution :O(n^2); 

        int ans =-1 ; 

        for (int i=1 ;i<=n ;i++ ){
            int left = generateSum(1,i); 
            int right = generateSum(i,n);
            if (left == right ){
                ans = i ;
            }
        }   
        return ans;
    }
};