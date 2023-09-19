class Solution {
public:
    bool asteroidsDestroyed(int mass, vector<int>& asteroids) {
        long long ans = mass ;
        int n = asteroids.size();
        sort(asteroids.begin() , asteroids.end()) ; 

        for (int i=0 ;i<n ;i++){
            if (ans>= asteroids[i]){
                ans += asteroids[i] ;
            }
            else{
                ans =0 ;
            }
        }

        if (ans == 0 ){
            return false;
        }
        return true ;
        
    }
};