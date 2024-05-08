class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) {
        int n = score.size(); 
        vector<string> ans (n);
        priority_queue<pair<int, int>> pq; 
        for(int i=0 ;i< n ;i++ ){
            pq.push(make_pair(score[i] , i ));
        }
        //processing for gold 
        int index  ;
        
        index = pq.top().second;
       
        ans[index] = "Gold Medal";
        pq.pop();
        if (n==1 )return ans;


        // Silver Medal Processing 
        index = pq.top().second ; 
        
        ans[index] = "Silver Medal";
        pq.pop(); 

        if (n==2 )return ans;

        // Bronze Medal Processing 
        index = pq.top().second ; 
       
        ans[index] = "Bronze Medal"; 
        pq.pop(); 
        if (n==3 )return ans;

        long long int  rank = 4 ;

        while (!pq.empty()){
            index = pq.top().second;
            
            string temp = to_string(rank); 
            ans[index] = temp ; 
            rank ++ ;
            pq.pop();
        }

        return ans;

    }
};