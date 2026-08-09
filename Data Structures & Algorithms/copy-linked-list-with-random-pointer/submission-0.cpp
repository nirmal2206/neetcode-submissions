/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        unordered_map<Node*, Node*> copy;

        Node* curr = head;
        //1. create nodes with values
        while(curr){
            copy[curr] = new Node(curr->val);
            curr = curr->next;
        }

        //2. assign next and random pointers
        curr = head;
        while(curr){
            copy[curr]->next = copy[curr->next];
            copy[curr]->random = copy[curr->random];
            curr = curr->next;
        }

        return copy[head];
    }
};
