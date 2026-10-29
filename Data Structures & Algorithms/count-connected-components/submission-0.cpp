class Solution {
public:
    int countComponents(int n, vector<vector<int>>& edges) {

        vector<vector<int>> graph(n);

        for(auto edge: edges){
            graph[edge[0]].push_back(edge[1]);
            graph[edge[1]].push_back(edge[0]);
        }

        vector<bool> visited(n, false);

        int components = 0;

        for(int i=0;i<n;++i){
            if(!visited[i]){
               ++components;
               dfs(i, visited, graph);
            }
        }

        return components;
    }

    void dfs(int node, vector<bool>& visited, vector<vector<int>>& graph){
        visited[node]  = true; // mark visited

        for(auto neigh: graph[node]){
            if(!visited[neigh]){
                dfs(neigh, visited, graph);
            }
        }
    }
};
