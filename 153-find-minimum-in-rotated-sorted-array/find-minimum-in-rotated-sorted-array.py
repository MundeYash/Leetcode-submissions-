class Solution:
    def findMin(self, nums: List[int]) -> int:

    # optimised approach : binary search 
        n= len(nums)
        st= 0 
        en = n-1 
        ans=-1

        while (st<en):
            mid = (st + math.floor((en-st)//2))
            if (nums[mid]>=nums[0]):
                st = mid + 1
            else: en = mid 
        
        ans =st
        # if (st==n-1): ans =0 # no rotation is done 
        if(nums[st]>nums[0]):
            st=0
        return nums[st]