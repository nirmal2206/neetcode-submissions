class Solution {
public:
    bool validTree(int n, vector<vector<int>>& edges) {
        //Graph is a valid tree if
        // 1. has exactly n-1 edges for n nodes
        //    a. greater than n-1 edges means cycle is there
        //    b. lesser than n-1 edges means disconnected graph
        // 2. doesn't have a cycle

        //case 1: check edges
        if(edges.size() != n-1) return false;

        //case2: check for cycles
        vector<vector<int>> graph(n);

        for(auto edge: edges){
            // undirected graph - add both values as neighbors of each other
            graph[edge[0]].push_back(edge[1]);
            graph[edge[1]].push_back(edge[0]);
        }

        vector<bool> visited(n, false);

        for(int i=0;i<n;++i){
            if(!visited[i] && hasCycle(i, -1, visited, graph)) return false;
        }

        return true;
    }

    bool hasCycle(int node, int prev, vector<bool>& visited, vector<vector<int>>& graph) {

        visited[node] = true; // mark the node as visted

        for(auto neigh: graph[node]){
            if(neigh == prev) continue;

            if(visited[neigh]) return true;

            if(hasCycle(neigh, node, visited, graph)) return true;
        }

        return false;
    }
};
