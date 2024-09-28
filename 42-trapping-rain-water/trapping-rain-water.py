class Solution(object):
    def trap(self, arr):
        """
        :type height: List[int]
        :rtype: int
        """
        #optimised solution ,time : O(n), space :O(1)
        n = len(arr)
        left =0  
        right =n-1 
        leftMax =-1 
        rightMax=-1
        sum=0

        while (left<=right):
            if(arr[left]<=arr[right]):

                if(arr[left]>=leftMax):
                    leftMax = arr[left]
                
                else:
                    #water will be trapped
                    sum += (leftMax-arr[left])
                
                left = left + 1
                
            else :
                if(arr[right]>=rightMax):
                    rightMax=arr[right]
                
                else:
                    #water will trap
                    sum += (rightMax-arr[right])
                
                right = right -1 
        
        return sum 

        