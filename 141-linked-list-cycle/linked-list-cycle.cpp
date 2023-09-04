/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:

// two pointer concept  , time complexity O(n) , space :O(n)
    bool hasCycle(ListNode *head) {
      // brute force approach : hastset appraoch  ;
      unordered_set<ListNode* > st ; 
      while (head != NULL){

          // check the prsence ;
          if(st.find(head)!= st.end()){
              return true  ; // presence of node aready means loop 
          }
          // insert head 
          st.insert(head) ; 
          // update the head ; 
          head = head->next;
      }
      return false ;
        
    }
};