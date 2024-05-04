class Solution:
    def numRescueBoats(self, people: List[int], limit: int) -> int:
        people.sort()

        i = 0
        j = len(people)-1
        boat = 0

        while(i<=j):
            if people[j]+people[i] <= limit:
                i+=1
            j-=1
            boat+=1

        return boat