class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int,int>>> graph(n+1);

        for(auto& e: times){
            graph[e[0]].push_back({e[1], e[2]});
        }

        vector<int> dist(n+1, INT_MAX);
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int, int>>> pq;

        dist[k] = 0;
        pq.push({0, k});

        while(!pq.empty()){
            auto [time, node] = pq.top();
            pq.pop();

            // skip as the curr weight is already greater than the best weight
            if(time > dist[node]) continue;

            for(auto [neighbour, neighTime]: graph[node]){

                int newTime = time + neighTime;
                // curr path time < best time till now update best time and push to queue
                if(newTime < dist[neighbour]){
                    dist[neighbour] = newTime;
                    pq.push({newTime, neighbour});
                }
            }
        }

        int answer = *max_element(dist.begin() + 1, dist.end());
        return answer == INT_MAX ? -1 : answer;
    }
};
