class Solution {
public:
    vector<int> sortEvenOdd(vector<int>& nums) {
        // concept : two arrays and sorting 
        vector<int > ans , oddDec, evenInc; 
        int n = nums.size(); 

        for(int i= 0;i<n ;i++ ){
            int value = nums[i];
            if (i &1) oddDec.push_back(value ); 
            else evenInc.push_back(value);
        }
        sort(evenInc.begin() , evenInc.end()); 
        sort(oddDec.begin() , oddDec.end(), greater<int>());
        int i=0 ,j=0 ; 
        while (i<evenInc.size() and j<oddDec.size()){
            ans.push_back(evenInc[i++]); 
            ans.push_back(oddDec[j++]);
        }

        while (i<evenInc.size()){
              ans.push_back(evenInc[i++]); 
        }
        while (j<oddDec.size()){
             ans.push_back(oddDec[j++]);
        }

        return ans;


    }
};