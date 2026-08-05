class Solution {
public:
    map<string,vector<string>> gr;
    multiset<string>edge;
    void dfs(string sr,vector<string>&vv){
        auto u = sr;
        // for(auto ds : gr[sr]){
        //     string ed = sr+"#"+ds;
        //     if(edge.count(ed)!=0){
        //         edge.erase(ed);
        //         dfs(ds,v);
        //     }
        // }
        while (!gr[u].empty()) {
            auto it = gr[u].begin();
            string v = *it;
            gr[u].erase(it);   // graph se edge hatao
            dfs(v,vv);
        }
        vv.push_back(sr);
        return ;
    }
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        gr.clear();
        edge.clear();
        for(auto tc :tickets){
            gr[tc[0]].push_back(tc[1]);
            edge.insert(tc[0]+"#"+tc[1]);
        }
        for(auto & p:gr) sort(p.second.begin(),p.second.end());
        vector<string>v;
        dfs("JFK",v);
        reverse(v.begin(),v.end());

        
        return v;
    }
};
