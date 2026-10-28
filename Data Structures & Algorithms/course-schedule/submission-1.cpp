class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> graph(numCourses);

        for(auto& p: prerequisites){
            graph[p[1]].push_back(p[0]);
        }

        // 0 - not visited(white), 1 - visting(gray), 2 - visited(black)
        vector<int> state(numCourses, 0);

        for(int i=0;i<numCourses;++i){
            if(state[i] == 0 && hasCycle(i, graph, state)) return false;
        }

        return true;
    }

    bool hasCycle(int node, vector<vector<int>>& graph, vector<int>& state){

        state[node] = 1; // visting

        for(auto neigh: graph[node]){
            if(state[neigh] == 1) return true; // already in visiting list - cycle detected
            if(state[neigh] == 0 && hasCycle(neigh, graph, state)) return true;
        }

        state[node] = 2; // visited
        return false;
    }
};
