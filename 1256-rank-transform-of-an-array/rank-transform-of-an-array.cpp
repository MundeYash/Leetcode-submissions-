class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        // heap based approach 
       
        priority_queue<int, vector<int> , greater<int>>pq;
        int n = arr.size(); 
        int preVal = INT_MIN; 
        int preRank=-1 ; 
        unordered_map<int , vector<int>> mp ;
        for (int i=0 ;i<n ;i++ ){
                mp[arr[i]].push_back(i); 
                  pq.push(arr[i]);

        }
        int rank =1;
        while (!pq.empty()){
            int topVal = pq.top(); 
            pq.pop();
            if (topVal == preVal){
                continue;
            }
            else{
               for(auto j: mp[topVal]){
                arr[j] = rank;
               } 
            }
        
            preVal = topVal ; 
            preRank = rank ;
                rank++ ;

        }
        return arr;
    }
};