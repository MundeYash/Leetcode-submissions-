class Solution:
    def getSneakyNumbers(self, nums: List[int]) -> List[int]:
        n = len(nums)
        update = [0]* n
        ans =[]
        for i in range(n):
            index = nums[i]
            update[index] = update[index] + 1
        
        for i in range (n):
            if(update[i]>1):
                ans.append(i)
        
        return ans




        