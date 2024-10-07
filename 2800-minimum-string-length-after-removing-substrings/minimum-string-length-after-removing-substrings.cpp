class Solution {
public:
    int minLength(string s) {
        int n = s.length (); 
        size_t pos ;
     while (true ){
        bool result = false ;
        pos = s.find("AB");
         if (pos != string::npos) {
        // means string is finded 
            s.erase(pos, 2);
            result = true ;
            }


        pos = s.find("CD");
        if (pos != string::npos) {
        // means string is finded 
        result = true ;
            s.erase(pos, 2);
            }

            if (result == false) break ; 

     }
     cout<<s<<endl;

     return s.length ();
    }
};