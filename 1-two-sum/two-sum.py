class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        n =len(nums)
        left =0 
        right =n - 1 
       
        ans =[]
        for i in range(n):
            for j in range(i+1,n):
                if( (nums[i] + nums[j])== target  ):
                    ans.append(i)
                    ans.append(j)
                    return ans
        
        if(len(ans)==0 ): ans.append(-1)
        return ans
     
        