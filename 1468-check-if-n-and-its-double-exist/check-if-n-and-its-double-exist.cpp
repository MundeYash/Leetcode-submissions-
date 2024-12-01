class Solution {
public:
    bool checkIfExist(vector<int>& arr) {
        // map based solution 
        unordered_map<int , int> mp ; 
        int n = arr.size() ; 
        for (int i=0 ;i<n ;i++ ){
            mp[arr[i]] ++; 

        }

        for (int i=0 ;i<n ;i++){
            int value = arr[i];
            if (arr[i]== 0 ){
                if (mp[arr[i]] >1)return true ; 
                else continue ;
            }
            if (mp.find(2*value)!= mp.end()  ) {
                cout<<arr[i]<<","<<2*arr[i]<<"| ";
                return true  ; 
            }
           
        }
        return false;
    }
};