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
    void reorderList(ListNode* head) {
        ListNode *slow = head, *fast = head;
        //1. Find the middle
        while(fast->next && fast->next->next){
            slow = slow->next;
            fast = fast->next->next;
        }

        //2. reverese 2nd half
        ListNode *secondHalf = slow->next;
        slow->next = nullptr; // split list into two halves
        ListNode *prev = nullptr;
        ListNode *curr = secondHalf;

        while(curr){
            ListNode *tmpNext = curr->next;
            curr->next = prev;
            prev = curr;
            curr = tmpNext;
        }
        
        // 'prev' is now the head of the reversed second half
        // 3. Merged two interval alternatively
        ListNode* firstHalf = head;
        secondHalf = prev;

        while(secondHalf){
            ListNode* tmp1 = firstHalf->next;
            ListNode* tmp2 = secondHalf->next;

            firstHalf->next = secondHalf;
            secondHalf->next = tmp1;

            firstHalf = tmp1;
            secondHalf = tmp2;
        }
    }
};
