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
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(!head || k==1) return head;

        ListNode dummy(0);
        dummy.next = head;

        ListNode* start = &dummy;
        ListNode* end = &dummy;

        while(end->next != nullptr){
            for(int i=0;i<k && end!=nullptr; ++i){
                end = end->next;
            }
            if(end == nullptr) break;

            ListNode* beginGroup = start->next;
            ListNode* nextGroup = end->next;

            end->next = nullptr; // detach next group

            start->next = reverseList(beginGroup); // reverse the curr group

            // Connect the reversed group back to the list
            // 'beginGroup' is now the tail of the reversed group
            beginGroup->next = nextGroup;

            // Move pointers for the next iteration
            start = beginGroup;
            end = start;
        }
        return dummy.next;
    }

    ListNode* reverseList(ListNode* head){
        ListNode* prev=nullptr;
        ListNode* curr=head;
        while(curr != nullptr){
            ListNode* next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        return prev; // Returns the new head of the reversed group
    }
};
