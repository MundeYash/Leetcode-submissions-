/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    void reverseLL (ListNode* &head ){
        ListNode* curr = head ; 
        ListNode* prev = NULL ; 
        while (curr ){
            ListNode* nextP = curr ->next; 
            curr ->next = prev ; 
            prev = curr ; 
            curr = nextP ;

        }
        head = prev ; 
        return ;
    }
    ListNode* doubleIt(ListNode* head) {
        // direct approach without storage 
        // concept : Reverse Link list 
        reverseLL (head );
        ListNode* ans = NULL ; 
        ListNode* temp = ans ;
        int carry = 0 ;
        while (head!= NULL   ){
            int sum = (head->val *2 ) + carry ;
            int value = sum %10 ; 
            carry = sum /10 ;
            if (!ans) {
                ans = new ListNode(value);
                temp = ans;
            } 
            else {
                temp->next = new ListNode(value);
                temp = temp->next;
            }
            
            head = head ->next; 
        }
        if (carry !=0 ){
             int sum =  + carry ;
            int value = sum %10 ; 
            carry = sum /10 ;
           
                temp->next = new ListNode(value);
              
            
            

        }
        reverseLL(ans);
        return ans;



    }
};