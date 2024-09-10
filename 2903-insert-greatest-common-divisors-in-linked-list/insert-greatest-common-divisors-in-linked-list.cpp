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
// function for finding the GCD of two number 
    int gcd(int a, int b ){
        while (a>0 && b>0 ){
            if (a>b ){
                a  = a%b;
            }
            else{
                b = b%a;
            }
        } 

        if (a==0 )return b; 
        return a;
    }


    ListNode* insertGreatestCommonDivisors(ListNode* head) {
if (!head || !head->next) {
        // No nodes or a single node
        return head;
    }
    
    // Traverse the linked list and insert GCD nodes
    ListNode* temp = head;  // Keep the reference to the original head
    
    while (head != NULL && head->next!= NULL ) {
        int currVal = head->val;
        int nextVal = head->next->val;
        int gcdValue = gcd(currVal, nextVal);
        
        // Create a new node with the GCD value
        ListNode* newNode = new ListNode(gcdValue);
        
        // Insert the new node between head and head->next
        newNode->next = head->next;
        head->next = newNode;
        
        // Move the head pointer to the node after the newly inserted one
        head = newNode->next;
    }

    return temp;  // Return the original head of the modified list

    }
};