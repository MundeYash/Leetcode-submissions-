class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int power) {
        // int ans =0 ; 
        // int score =0 ; 
        // sort(tokens.begin() ,tokens.end());
        // int n = tokens.size();
        // for (int i=0 ;i<n ;i++ ){

        //     int val1 =0 , val2 =0 ;
        //     bool check1= false , check2= false;
        //     if (power>= tokens[i]){
        //         check1= true;
        //         score ++ ; 
               
        //        val1 = score ;
        //        score -- ;
        //     }

        //     if (score>=1 ){
        //         check2= true ; 
        //         score -- ; 
               
        //         val2 = score ;
        //         score ++ ;

        //     }
        //     if (check1== false and check2== false){
        //         // means nothing done 
        //         continue;
        //     }

        //     else if (val1>val2  and (check1== true )){
        //         // means check1 will run
        //         score -- ; 
        //          power = power + tokens[i];

        //     }
        //     else if (val2>val1 and (check2== true )){
        //         score ++ ;
        //          power = power - tokens[i];
        //     }

        //     ans = max(ans, val1); 
        //     ans = max(ans,val2);

        // }
        // return ans;
         int ans = 0;
    int score = 0;
    int n = tokens.size();
    sort(tokens.begin(), tokens.end());

    int left = 0, right = n - 1;

    while (left <= right) {
        if (power >= tokens[left]) {
            power -= tokens[left];
            score++;
            left++;
            ans = max(ans, score);
        } else if (score > 0) {
            power += tokens[right];
            score--;
            right--;
        } else {
            break;
        }
    }

    return ans;
    }
};