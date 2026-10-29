class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> graph(numCourses);

        for(auto preq: prerequisites){
            graph[preq[1]].push_back(preq[0]);
        }

        //0 - not visited, 1 - visting, 2 - visited
        vector<int> state(numCourses, 0);
        vector<int> order;


        for(int i=0;i<numCourses;++i){
            if(state[i] == 0 && hasCycle(i, state, order, graph)){
                return {};
            }
        }

        reverse(order.begin(), order.end()); // order is in reversed order
        return order;
    }

    bool hasCycle(int node, vector<int>& state, vector<int>& order, vector<vector<int>>& graph){

        state[node] = 1; // mark visiting

        for(auto neigh : graph[node]){
            if(state[neigh] == 1) return true;

            if(state[neigh] == 0 && hasCycle(neigh, state, order, graph)) return true;
        }
        
        state[node] = 2; // mark visited

        order.push_back(node);

        return false;
    }
};
