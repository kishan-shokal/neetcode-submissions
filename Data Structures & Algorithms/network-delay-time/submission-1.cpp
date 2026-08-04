class Solution {
public:
    vector<vector<pair<int,int>>>gr;
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        gr.resize(n+1,vector<pair<int,int>>());
        for(auto v : times){
            gr[v[0]].push_back({v[1],v[2]});
        }
        vector<int> dist(n+1,INT_MAX);
        dist[0]=0;
        dist[k]=0;
        priority_queue<
            int,
            vector<int>,
            greater<int>
        > qu;
        qu.push(k);
        int cnt = 0;
        while(!qu.empty()){
            auto fr = qu.top();
            qu.pop();
            for(auto node :gr[fr]){
                int ds = dist[fr]+node.second;
                if(dist[node.first]>ds){
                    qu.push(node.first);
                    dist[node.first]=ds;
                }
                cnt++;
            }
        }
        int ans = 0;
        for(auto x:dist) ans=max(ans,x);
        
        if(ans==INT_MAX) return -1;
        return ans;


    }
};
