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
    struct CompareNode{
        bool operator()(ListNode* a, ListNode* b){
            return a->val > b->val;
        }
    };
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<ListNode*, vector<ListNode*>, CompareNode> minHeap;

        ListNode ans(0);
        ListNode* curr = &ans;

        //1. Push the head of every non-empty list into the heap
        for(ListNode* node: lists){
            if(node != nullptr) minHeap.push(node);
        }

        while(!minHeap.empty()){
            // Get the min node from the top
            ListNode* smallest = minHeap.top();
            minHeap.pop();

            curr->next = smallest;
            curr = curr->next;

            if(smallest->next != nullptr){
                minHeap.push(smallest->next);
            }
        }
        
        return ans.next;
    }
};
