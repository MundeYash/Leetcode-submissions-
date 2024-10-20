bool  comp(pair<int , int> a , pair<int , int> b ){
    if (a.first> b.first )return true ; 
    else if (a.first == b.first ){
        if (a.second> b.second )return true ; 
    }
    return false;
}
class Solution {
public:

    vector<int> findXSum(vector<int>& nums, int k, int x) {
         vector<int> ans ; 
        int n  = nums.size() ; 
       
        for (int i=0 ;i<(n-k+1) ;i++ ){

            vector<pair<int , int>> pq ; 
            unordered_map<int , int> mp ;
            for (int j=i; j<=min((i+k-1),n-1);j++ ){
                mp[nums[j]]++;
              
            }
            cout<<"Map print ";
            for (auto it: mp){
                cout<<"it.second ->"<<it.second <<", it.first->"<<it.first<<" ! ";
                pq.push_back({it.second, it.first });
            }
            cout<<endl<<"Pairs :";

            sort(pq.begin(),pq.end(),comp);
            cout<<"after sorting :";
           for(auto p : pq)cout<<"("<<p.first <<","<<p.second<<") | ";
           cout<<endl;
            int value =0 ;
            int cnt = x; 
            int index=0 ;
            while (index<cnt && index<pq.size()){
                
                int freq = pq[index].first ; 
                int number = pq[index].second ;
                value += (freq * number );
                index ++ ;
            }
            ans.push_back(value );
        }
         return ans ; 
    }
};