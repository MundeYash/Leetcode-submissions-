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
    int  lengthLL(ListNode* head ){
        int count =0 ; 
        while (head ){
            count ++ ; 
            head = head ->next; 
        }
        return count ; 
    }
    ListNode* removeNthFromEnd(ListNode* head, int k) {
        if (!head|| (!head->next and k==1 ) )return NULL ; // no need of deletion 

        // step 1: find the length of the link list 
        int n = lengthLL (head ); //O(n)
        ListNode* temp = head;
        if (k== n ){
            // deletion of head node 
            head = head ->next; 
            temp->next = NULL ; 
            delete temp ; 
            return head; 
        }

        // other cases 
        k = k %n ; // to make the k in the range of n 
        int cnt =1 ;

        while(cnt<(n-k)){//O(k)

            temp = temp->next; 
            cnt ++ ; 
        }

        // we have to delte the temp ->next node 
        if (temp->next == NULL || k==0 ){
            // deletion of last node which is null and (no need of deletion )
            return head ; 

        }

        // other solvable case 
        ListNode* delNode = temp->next; 
        temp->next = delNode->next; 
        delete delNode; 
        return head; 

    }
};