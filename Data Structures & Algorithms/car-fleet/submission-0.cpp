class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        int n = position.size();
        if(n==0) return 0;

        vector<pair<int, int>> cars;
        for(int i=0;i<n;++i){
            cars.push_back({position[i], speed[i]});
        }

        sort(cars.begin(), cars.end(), [] (const pair<int, int> &a, const pair<int, int> &b){
            return a.first > b.first;
        });

        float maxTime = 0.0f;
        int fleets = 0;
        for(auto &[pos, t]: cars){
            float time = (float)(target - pos)/t;
            // If this car is slower than the fleet ahead, it forms a new fleet 
            if(time > maxTime){
                maxTime = time;
                fleets++;
            }
            // Else: time <= maxTime, so it catches up and merges (do nothing)
        }
        return fleets;
    }
};
