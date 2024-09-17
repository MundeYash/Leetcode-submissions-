class Solution {
    public int maxProduct(int[] arr) {
        int n = arr.length;
        if (n==1 )return arr[0];
	  int ans =-100000 ; 
	  for (int i=0 ;i<n ;i++ ){
	        int   prod =1 ;
	      for (int j=i ;j<n ;j++ ){
	        
	       //   for (int k=i ; k<=j ;k++ ){
	       //         prod *= (arr[k]);
	       //   }
	          prod *= arr[j];
	          ans = Math.max(ans , prod);
	      }
	  }
	  return ans;
    }
}