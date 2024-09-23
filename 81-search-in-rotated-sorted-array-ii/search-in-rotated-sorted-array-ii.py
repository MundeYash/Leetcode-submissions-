class Solution:
    def search(self, nums: List[int], target: int) -> bool:
        #brute force approach : linear search 
        n = len(nums)
        for i in range(n):
            if (nums[i]== target ):
                return True 
            
        return False
        