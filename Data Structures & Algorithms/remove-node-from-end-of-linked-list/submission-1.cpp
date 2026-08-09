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
    ListNode* removeNthFromEnd(ListNode* head, int n) {

        ListNode* dummy = new ListNode();
        dummy->next = head;
        ListNode* slow = dummy, *fast=dummy;

        // Move fast node by n+1 steps
        for(int i=0;i<=n;++i){
            fast = fast->next;
        }

        // move both slow and fast untill fast == null
        // now slow is at a pos before the Nth node to be removed
        while(fast != nullptr){
            slow = slow->next;
            fast = fast->next;
        }

        // remove the node
        ListNode* toDelete = slow->next;
        slow->next = slow->next->next;
        delete toDelete;

        return dummy->next;
    }
};
