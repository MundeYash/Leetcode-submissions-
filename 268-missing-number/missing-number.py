class Solution:
    def missingNumber(self, nums: List[int]) -> int:
        res =0 
        n = len(nums)
        for i in range(n):
            res = res^i 
            res = res^nums[i]
        
        res = res ^ n 

        return res
        