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
int lengthLL(ListNode* head ){
    int count =0 ; 
    while (head != NULL){
        count++ ;
        head = head->next ;
    }
    return count ;
}
    ListNode* removeNthFromEnd(ListNode* head, int k) {
        // time : O(2n) ,space : O(1)
        if (head == NULL) return NULL ; 
        int n = lengthLL(head) ;

        if (n == k ){
            // deletion at front 
            ListNode*temp  =  head; 
            head = head ->next ; 
            temp->next = NULL  ;
            delete temp ; 
            return head ;

        }

        k = k % n ; 

        int count =1 ; 
        ListNode* temp = head ;
        while(count <n-k ){
            count ++ ; 
            temp = temp->next ;

        }
        if (temp->next == NULL){
            return head;
        }
        ListNode* newNode = temp->next ; 
        temp->next = newNode->next; 
        newNode->next = NULL ; 
        delete newNode ; 
        return head;

        
    }
};