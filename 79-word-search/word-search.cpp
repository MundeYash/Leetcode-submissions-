class Solution {
public:

// function for finding the word 

bool solve (vector<vector<char >> & board , string word, int i , int j , int k , int n  , int m ){
    // base case (means word finded )
    if (word.size()==k){
        return true ; 
    }
    // other wise check out of range cases 
    if (i<0 || j<0 || i>=n || j>=m|| word[k]!= board[i][j]){
        return false;
    }

    // recursive case of finding the words 
    char ch = board[i][j] ; 
    board[i][j]='.'; //means one character from word finded 

    // for horizontall and vertical movement 
    int x [] = {+1 , 0 , -1  , 0 } ; 
    int y [] = {0, 1, 0 , -1 } ; 


    // for checking in the movement 
    for (int index =0 ;index <4 ; index ++){
        int ni = i + x[index] ; 
        int nj = j+ y[index ] ;

        if (solve(board , word , ni , nj , k+1 , n ,m )== true  ) return true ; // k+1 because one word is already finded 
    }

    // after checking in all 4 directions not finded the word 
    // backtrack 
    board[i][j] =ch ; 
    return false ;
}


    bool exist(vector<vector<char>>& board, string word) {
     int n = board.size() ; 
    int m = board[0].size() ; 
    for (int i=0 ;i<n ;i++){
        for (int j= 0 ;j<m ;j++){

            if (solve (board  , word ,i , j , 0 , n , m )== true )return true ;
        }
    }

    return false;// means you have checked over all the board cells 
    }
};