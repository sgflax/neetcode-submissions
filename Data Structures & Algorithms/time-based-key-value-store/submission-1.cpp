class TimeMap {
public:
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        timemap[key].push_back({value, timestamp});
    }
    
    string get(string key, int timestamp) {
        auto& values = timemap[key];
        string res = "";
        int l = 0;
        int r = values.size() - 1;
        while(l <= r){
            int mid = l + (r - l) / 2;

            if(values[mid].second <= timestamp){
                //save valid candidate if we cant find later one
                res = values[mid].first;
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }
        return res;
    }
    unordered_map<string, vector<pair<string, int>>>timemap;
};
