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
    bool hasCycle(ListNode *head) {
        //Concept : -> map based solution : 

        unordered_map<ListNode* ,int > mp ; 
        while (head ){
            if (mp.find(head)!= mp.end())return true ;
            mp[head] = head->val ; 
            head = head-> next ;
        }
        return false;
        
    }
};