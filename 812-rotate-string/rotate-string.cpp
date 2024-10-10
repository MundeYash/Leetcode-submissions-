class Solution {
public:
    bool rotateString(string s, string goal) {
        // brute force approach : rotate each time and check 

        // brute force rotate each time and check 
    int n = s.size(); 

    if(s==goal )return  1; 
    
    for (int i=0 ;i<n ; i++ ){
        if(s==goal ){
            return 1 ; 
        }
        char ch = s[n-1]; 
        // rotate array each time by one unit 
        for (int j=n-2;j>=0 ;j-- ){
            s[j+1] = s[j]; 

        }
        s[0] = ch ; 
        // cout<<s <<endl;
    } 
    return 0;
    }
};