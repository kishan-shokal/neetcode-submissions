class Solution {
public:
    bool canFinish(int n, vector<vector<int>>& pre) {

        vector<vector<int>>gr(n,vector<int>());
        vector<int>v(n,0),seq;
        for(auto edge:pre){
            gr[edge[1]].push_back(edge[0]);
            v[edge[0]]++;
        }
        queue<int>qu;
        for(int i=0;i<n;i++){
            if(v[i]==0) qu.push(i);
        }
        while(!qu.empty()){
            auto a = qu.front();
            seq.push_back(a);
            qu.pop();
            for(auto b:gr[a]){
                v[b]--;
                if(v[b]==0) qu.push(b);
            }
        }
        return seq.size()==n;
        
    }
};
