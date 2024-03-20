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
        while (head ){
            count ++  ; 
            head  = head ->next ; 
        }

        return count ; 
    }
    void array2LL(ListNode* &head , vector<int> ans ){
        ListNode* dummy = new ListNode(0); 
        ListNode* temp = dummy ;

        for (int i=0 ;i<ans.size(); i++ ){

            cout<<ans[i]<<" ";
            temp->next = new ListNode(ans[i]);
            temp = temp ->next; 

        }

        head = dummy->next ;
    }
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
        
        ListNode* temp= list1;

        int n = lengthLL(list1); 
        int m = lengthLL (list2);

        int count =0 ; 
        vector<int> ans;

        while (count< a && temp != NULL){

            ans.push_back(temp->val);
         
            temp = temp ->next;
            count ++ ; 
        }

        while (count <=b && temp != NULL  ){
            count ++ ; 
            temp = temp->next; 
        }


        ListNode* temp2 = list2 ; 
        while (temp2 ){

            ans.push_back(temp2->val);
            temp2 = temp2 ->next ;
        }


        while (temp!= NULL and count <n ){

           
            ans.push_back(temp ->val );
            temp = temp ->next ;
        }

        ListNode* head = NULL ;

        array2LL(head , ans );

        cout<<"Hello";
        return head ;
    }
};