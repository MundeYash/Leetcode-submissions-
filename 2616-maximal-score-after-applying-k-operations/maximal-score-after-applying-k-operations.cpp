class Solution {
public:

    long long maxKelements(vector<int>& nums, int k) {
        // priority queue , max heap based question 
        priority_queue<long long > pq ; 
        for (int i= 0 ;i<nums.size() ;i++ ){
            pq.push((long long )nums[i]);
        }
        long long sum =0 ; 

        while (k--){
            int value = pq.top() ;
            cout<<value<<" ";
            sum += value ; 
            pq.pop() ; 
            long long  value2 =(value/3);
            if (value %3 != 0 ) value2 ++ ; 
            pq.push(value2);

        }
        return sum ;
    }
};