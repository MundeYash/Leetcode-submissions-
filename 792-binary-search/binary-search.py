class Solution:
    def search(self, nums: List[int], target: int) -> int:
        #implementing binary search in python 
        n = len(nums)
        s=0 
        e = n-1 
        while (s<=e):
            mid = (s+ (e-s)//2)
            value = nums[mid]
        
            if (value == target):
                return mid
            elif (value>target):
                e = mid -1 
            else : s  = mid + 1
        
        return -1 
        