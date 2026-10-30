// Find Union by rank
class Solution {
    vector<int> parent, rank;

    int findParent(int node){
        if(parent[node] == node) return node;
        return parent[node] = findParent(parent[node]);
    }

    void unionByRank(int u, int v){
        int ulp_u = findParent(u);
        int ulp_v = findParent(v);

        if(ulp_u == ulp_v) return;

        if(rank[ulp_u] < rank[ulp_v]){
            parent[ulp_u] = ulp_v; // attach smaller to the larger
        } else if(rank[ulp_u] > rank[ulp_v]) {
            parent[ulp_v] = ulp_u; // attach smaller to the larger
        } else {
            parent[ulp_v] = ulp_u;  // ← attach one under the other
            rank[ulp_u]++;          // ← then increment
        }
    }
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {

        int n = edges.size();
        parent.resize(n+1);
        rank.resize(n+1, 0);

        for(int i=1;i<=n;++i){
            parent[i] = i;
        }

        for(auto& edge: edges){
            int u = edge[0], v = edge[1];

            if(findParent(u) == findParent(v)) return edge;

            unionByRank(u, v);
        }
    }
};
