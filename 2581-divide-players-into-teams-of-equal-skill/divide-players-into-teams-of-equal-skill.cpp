class Solution {
public:
    long long dividePlayers(vector<int>& skill) {

        sort(skill.begin() , skill.end())  ; 
        int n  = skill.size() ; 
        // two pointer approach 
        int value = skill[0] + skill[n-1] ;
        long long ans =0 ;

        int st =0 , end = n-1 ; 
        while (st<end ) {
            int sum  = (skill[st] + skill[end]) ; 
            
            if (sum == value ){
                long long temp = (skill[st ] *(long long  )skill[end]) ; 
                ans += temp ;
                st++ ;
                end -- ;
            }
            else{
                return -1;
            }
        }

        return ans;
    }
};