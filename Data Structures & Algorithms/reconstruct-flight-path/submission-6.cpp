class Solution {
public:
    map<string,vector<string>> gr;
    multiset<string>edge;
    void dfs(string sr,vector<string>&v){
        for(auto ds : gr[sr]){
            string ed = sr+ds;
            if(edge.count(ed)!=0){
                auto it = edge.find(ed);
                if (it != edge.end()) {
                    edge.erase(it); 
                }
                // edge.erase(ed);
                dfs(ds,v);
            }
        }
        v.push_back(sr);
        return ;
    }
    void dfs1(string sr,vector<string>&v){
    

        while (!gr[sr].empty()) {
            auto it = gr[sr].begin();
            string d = *it;
            gr[sr].erase(it); 
            dfs(d,v);
        }
        v.push_back(sr);
        return ;
    }
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        gr.clear();
        edge.clear();
        for(auto tc :tickets){
            gr[tc[0]].push_back(tc[1]);
            edge.insert(tc[0]+tc[1]);
        }
        for(auto & p:gr) sort(p.second.begin(),p.second.end());
        vector<string>v;
        dfs("JFK",v);
        reverse(v.begin(),v.end());

        
        return v;
    }
};
