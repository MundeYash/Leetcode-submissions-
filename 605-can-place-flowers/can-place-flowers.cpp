class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int count ) {
        if (count ==0 )return true ;
        int n = flowerbed.size() ;
        if (count ==1 and n==1   ){
            if (flowerbed[0]== 0 )return true ; 
            else return false;

        }

        //edge cases 
        //front cases 
        if (flowerbed[0]==0 and flowerbed[1]!=1 ) {
            flowerbed[0] =1;
            count -- ;
        }
        int i=1 ;
      while (i<n-1 ){
            if (flowerbed[i-1] !=1 and flowerbed[i+1]!= 1 and flowerbed[i]==0 ){

                flowerbed[i]=1 ;
                count -- ;
                 i +=2 ;
            }
            else{
                i++;
            }

           
        }

        // end case 
        if(flowerbed[n-1]==0 and flowerbed[n-2] ==0  ) {
            flowerbed[n-1] =1 ;
            count --;
        }

        if (count <=0 )return true ; 
        
        return false;
        
    }
};