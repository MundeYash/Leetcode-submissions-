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
        ListNode* prev = NULL ; 
        ListNode* curr = head ; 

        while (curr )
        {
            ListNode* nextP = curr->next; 
            curr->next = prev ; 
            prev = curr ; 
            curr = nextP;

        }
        head = prev ;
        return ;
    }
    ListNode* removeNodes(ListNode* head) {
        if (!head )return NULL;
        reverseLL (head);
        // stack based approach  : next greater and than create link list 
        stack<int> st  ; 
        st.push(head->val);
       
        ListNode* ans =NULL;
        vector<int> ans1;
        ListNode* temp = ans ;
        while (head ){
            if (!st.empty() && head->val>= st.top()){
                // means not exists next greater of current node value 
                ans1.push_back(head->val);
                ans = new ListNode(head->val,ans);
                

                st.pop(); 
                st.push(head->val);
            }
            head = head->next;
            
        }
        // reverseLL(ans); 
     
        return ans;
    }
};