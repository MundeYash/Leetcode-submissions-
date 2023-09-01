class Solution {
public:
    int maxArea(vector<int>& height) {
        
        int maxArea = 0 ; 
        int n = height.size();


        // two pointer approach following 
        int left =0 , right = n-1 ; 
        while (left<= right ){
            int len = min(height[left]  , height[right ]) ; 
            int wid = (right - left ) ;

            int area = len * wid ; 
            if (area > maxArea ){
                maxArea = area ; 
            }


            // comparison pointer movement conditions 
            if (height[left ]<height[right ]){
                left ++ ;
            }
            else {
                right -- ;
            }
        }
            return maxArea;
    }


};