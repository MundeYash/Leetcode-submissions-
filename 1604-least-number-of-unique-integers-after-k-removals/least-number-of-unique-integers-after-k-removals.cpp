class Solution {
public:
    int findLeastNumOfUniqueInts(vector<int>& arr, int k) {
        // map concept : 
        int n  = arr.size();
        unordered_map<int , int > mp ; 
        for (int i=0 ;i<n ;i++ ){
            mp[arr[i]]++;
        }

        // priority queue for getting the elements with frequency in min order 
   
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

        for (auto it : mp ){
            pq.push(make_pair(it.second, it.first ));
        }

        int ans=0 ; 
        while (k>0){
            pair<int ,int> topElement = pq.top() ; 
            pq.pop();
            int freq = topElement.first; 
            int value = topElement.second;

            if (k>freq){
                k-= freq ;
                // n-=freq ;

            }
            else if (k== freq){
                 k-= freq ;

                n-=freq ;
            }
            else{
                int diff = (freq-k); 
                ans ++;
                // n-= diff ;
                k=0 ;
                break;
            }
        }
    

        while (!pq.empty()){
            // ans += pq.top().first ; 
            ans++;
            pq.pop();
        }
        return ans ;
    }
};