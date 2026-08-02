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

        auto& val = um[key];

        auto it = upper_bound(val.begin(), val.end(), make_pair(timestamp, string(127, '~')));
        if(it==val.begin()) return "";

        return prev(it)->second;

    }
};
