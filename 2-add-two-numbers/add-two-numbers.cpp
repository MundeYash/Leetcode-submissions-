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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        // time : O(max(n,m))  ,space : O(k)

        // some termination condition 
        if (11 == NULL )return l2 ; 
        if (l2 == NULL )return l1 ; 

        // if some other link list have also nodes 
        ListNode* dummy = new ListNode(0); // to have the access of the head 
        ListNode* temp = dummy ; // for movement 
        int carry =0 ;

        while (l1 != NULL || l2 != NULL || carry != 0 ){
            int sum =0 ; 
            if (l1!= NULL){
                sum += l1->val ; 
                l1= l1->next ;
            }
            if (l2!= NULL){
                sum += l2->val ; 
                l2= l2->next ;
            }
            sum += carry ; 
            carry = sum /10 ; 

            ListNode* newNode = new ListNode(sum%10 ) ; 
            temp->next = newNode  ; 
            temp = temp->next ;  

        }
        return dummy->next ;
        
    }
};