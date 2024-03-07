/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *;next
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    int lengthLL (ListNode* head ){

        int len =0 ; 
        while (head ){  
            len++ ;
          head = head ->next ; 
        }
        return len ;
    }
    ListNode* middleNode(ListNode* head) {
        // count method 
        int count =1 ; 
        int n = lengthLL (head );
        ListNode* temp = head;
        while (count  < (n/2)+1 ){

            head = head ->next ;
            count ++ ; 
        }

        return head ;
    }
};