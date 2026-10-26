/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    Node* cloneGraph(Node* node) {
        if(!node) return nullptr;
        return dfs(node);
    }

private:
    unordered_map<Node*, Node*> visited;

    Node* dfs(Node* node){

        if(visited.count(node)) return visited[node];

        Node* clone = new Node(node->val);

        visited[node] = clone; // mark visted before recursion to prevent cycle

        for(Node* neighbour: node->neighbors){
            clone->neighbors.push_back(dfs(neighbour));
        }
        
        return clone;
    }
};
