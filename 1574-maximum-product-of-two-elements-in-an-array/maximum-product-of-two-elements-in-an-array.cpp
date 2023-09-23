class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size() ; 
        int ans =1 ;

       // solving using the priority queue 
       priority_queue<int > pq(nums.begin() , nums.end());

       int first = pq.top() - 1;
       pq.pop();
       int second = pq.top() -1 ; 
       pq.pop();
       ans = first * second ; 



        if (ans ==1 )return 0 ; 
        return ans ;
        
    }
};