class Solution {
public:
    int diagonalSum(vector<vector<int>>& mat) {
        
        int sum =0  ; 
        int n = mat.size();
        int mid = (n/2);
    
        bool isEven = false ;
        if (n%2==0 ){
            isEven= true;
        }

       
       for (int i=0 ;i<n ;i++ ){

            if (isEven){
                sum += mat[i][i]; 
                sum += mat[i][(n-i-1)]; 
           
            }
            else{

                if (i==mid){
                      sum += mat[i][i]; 
                     
           
                }
                else{
                sum += mat[i][i]; 
                sum += mat[i][(n-i-1)]; 
           
                }
            }
          
          
           

       }

    
        // if (n%2 !=0 ){
        //     // odd value 
            
        //     sum  -= mat[n/2] [n/2];
        // }

       
       return sum ;
    }
};