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
    void array2LL(ListNode* &head ,vector<int> arr ){
         head = nullptr;
        ListNode* current = nullptr;
        
        // Iterate through the array to create nodes and link them
        for (int i = 0; i < arr.size(); ++i) {
            ListNode* newNode = new ListNode(arr[i]);
            
            if (head == nullptr) {
                head = newNode;
                current = newNode;
            } else {
                current->next = newNode;
                current = current->next;
            }
        }
        
        return ;
    }
    void reorderList(ListNode* head) {
       if (!head || !head->next) return;

        vector<ListNode*> nodes;

        // Store all nodes in the array
        ListNode* current = head;
        while (current) {
            nodes.push_back(current);
            current = current->next;
        }

        int left = 0, right = nodes.size() - 1;

        // Reorder the list using two pointers
        while (left < right) {
            nodes[left]->next = nodes[right];
            left++;

            if (left == right) break;

            nodes[right]->next = nodes[left];
            right--;
        }

        // Set the next of the last node to nullptr
        nodes[left]->next = nullptr;
        return ;

      
    }
};