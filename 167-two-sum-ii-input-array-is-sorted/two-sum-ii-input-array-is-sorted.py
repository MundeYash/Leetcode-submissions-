class Solution:
    def twoSum(self, numbers: List[int], target: int) -> List[int]:
        n = len(numbers)
        left =0 
        right =n-1 
        ans=[]
        while (left<right ):
            value = (numbers[left] +numbers[right ])
            if (value == target):
                ans.append(left + 1)
                ans.append(right + 1)
                return ans
            elif(value> target):
                right = right-1 
            else : left = left +1 
        return ans