class Solution {
public:

    // custom comaprator creation 
    bool static comparator (string a , string b ){
        return (a+b> b+a );
    }
    string largestNumber(vector<int>& nums) {
        // step1 : convert to string format 
        int n = nums.size();
        vector<string > ans ; 
        for (int i=0 ;i<n ;i++ ){
            ans.push_back(to_string(nums[i]));
        }

        sort(ans.begin() , ans.end(), comparator );

        // concatenation to resultant string 
        string result ; 
        for (int i=0 ;i<n ;i++ ){
            result += ans[i];
        }

        while (result[0]=='0' and result.size()>1 ){
            // erase it by one place ; 
            // because of no negative number availablity 
            result.erase(0,1);
        }

        return result ;
    }
};