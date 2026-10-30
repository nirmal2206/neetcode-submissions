// Find union by size
class Solution {
    vector<int> parent, size;

    int findParent(int node){
        if(parent[node] == node) return node;
        return parent[node] = findParent(parent[node]);
    }

    void unionBySize(int u, int v){
        int ulp_u = findParent(u);
        int ulp_v = findParent(v);

        if(ulp_u == ulp_v) return;

        if(size[ulp_u] < size[ulp_v]){
            parent[ulp_u] = ulp_v; // attach smallet to the bigger
            size[ulp_v] += size[ulp_u]; // update the size of the bigger = intial size + smaller size
        } else {
            parent[ulp_v] = ulp_u; // attach smallet to the bigger
            size[ulp_u] += size[ulp_v]; // update the size of the bigger = intial size + smaller size
        }
    }
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        parent.resize(n+1);
        size.resize(n+1, 1);

        for(int i=1;i<=n;++i){
            parent[i] = i;
        }

        for(auto& edge: edges){
            int u = edge[0], v = edge[1];

            if(findParent(u) == findParent(v)) return edge;

            unionBySize(u, v);
        }

    }
};
