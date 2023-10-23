class node{
    public : 
    int data ; 
    int row ; 
    int col ; 

    // default constructor 
    node(int d , int r , int c ){
        this ->data = d; 
        this ->row =r  ; 
        this->col = c ;
    }

} ; 

// custom comparator 
class comparator {

    public : 
    bool operator ()( node* a  , node* b ){
        return a->data  > b->data ; 
    }
} ;
class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
         vector<int> ans ; 

         int k = nums.size() ; 

         int mini = INT_MAX ; 
         int maxi = INT_MIN ; 

         priority_queue<node* , vector<node*> , comparator> pq ; 

         for (int i=0 ;i<k ;i++){
             int element = nums[i][0];
             mini = min (mini , element ) ; 
             maxi = max(maxi , element ) ; 

             pq.push(new node(element , i , 0)) ; 
         }

    int start = mini , end = maxi ; 
         while (!pq.empty()){
             node* temp = pq.top() ; 
             pq.pop() ; 

             mini = temp->data ; 

             if (maxi  - mini < end - start ){
                 start= mini ; 
                 end = maxi ; 
             }

             int i = temp->row ; 
             int j = temp->col ; 

             if (j+1 < nums[i].size() ){
                 maxi = max (maxi , nums[i][j+1]) ; 
                 pq.push(new node(nums[i][j+1] , i , j+ 1 )); 

             }
             else{
                 // till now is finded 
                 break ; 
             }

         }

         ans.push_back(start ) ; 
         ans.push_back(end) ; 
         return ans;

    }
};