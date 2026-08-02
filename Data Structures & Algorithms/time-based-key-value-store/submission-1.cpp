class TimeMap {
public:

    unordered_map<string, vector<pair<int, string>>> um;

    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        um[key].push_back({timestamp, value});
    }
    
    string get(string key, int timestamp) {
        
        if(um.find(key) == um.end()) return "";

        auto& values = um[key];

        int l=0, r=values.size()-1;
        string ans="";
        while(l<=r){
            int mid = l + (r-l)/2;
            // there exists a timestamp which is smaller then the asked timestamp
            // potential answer
            if(values[mid].first <= timestamp){
                ans=values[mid].second;
                l = mid+1; // Try to find a larger valid timestamp
            } else {
                // Timestamp too large, go left
                r = mid-1;
            }
        }
        return ans;
    }
};
