
class Solution {
    public int[] xorQueries(int[] arr, int[][] queries) {
        int q = queries.length; 
        int n = arr.length ; 
       int []ans =new int[q] ;
 
        for (int i=0 ;i<q;i++ ){
            int left = queries[i][0]; 
            int right = queries[i][1]; 
            int value =0 ; 
            while (left<=right){
                value ^= arr[left];
                left ++ ;
            }
            ans[i]=value;
          
        }
        return ans;
    }
}