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
    ListNode* reverseList(ListNode* head) {
        //ListNode* tail = head; // The head becomes the tail of the new list
        //Swap pointers a->b to a<-b
        ListNode* curr = head; // current node poistion (starts at the 'tail')
        ListNode* prev = nullptr; 

         //next reverse the next pointers to point backwards
        while (curr != nullptr) {
            ListNode* temp = curr->next; // save next item in the list
            curr->next = prev; // reverse order of pointers
            prev = curr; // update tracking pointer
            curr = temp; // move onto next item in the list
        }
        return prev;
    }
};
