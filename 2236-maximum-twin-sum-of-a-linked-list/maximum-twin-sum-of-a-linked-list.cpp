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
    int pairSum(ListNode* head) {
        // store some where 
        vector<int>temp ; 
        while (head ){
            temp.push_back(head->val); 
            head = head ->next; 
        }

        int n = temp.size();
        int st =0 , end =n-1 ; 
        int maxi =0 ;

        while (st<end ){
            int sum = temp[st] + temp [end]; 
            if (sum>maxi){
                maxi = sum ;
            }
            st++ ; 
            end --;
        }
        return maxi ;
        
    }
};