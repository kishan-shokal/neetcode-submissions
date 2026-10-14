class TimeMap {
public:
    unordered_map<string,vector<pair<int,string>>>mp;
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        mp[key].push_back({timestamp,value});

    }
    
    string get(string key, int timestamp) {
        auto & v = mp[key];
        
        // int ind = distance(
        //                 v.begin(),
        //                 upper_bound(
        //                     v.begin(), v.end(), timestamp,
        //                     [](int timestamp, const pair<int, string>& p) {
        //                         return timestamp < p.first;
        //                     }
        //                 )
        //             );
        int ind = distance(
                            v.begin(),
                            lower_bound(
                                v.begin(), v.end(), timestamp,
                                [](const pair<int, string>& p, int timestamp) {
                                    return p.first < timestamp;
                                }
                            )
                        );
        // if(ind>=v.size()) ind--;
        if(ind>=v.size() || v[ind].first>timestamp) ind--;
        if( (ind==0 && v[ind].first>timestamp) || ind<0) return "";
        

        
        return v[ind].second;
    }
};
