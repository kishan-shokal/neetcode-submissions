class Solution {
public:
    vector<vector<int>>gr;
    int ladderLength(string sw, string ew, vector<string>& arr) {
        arr.push_back(sw);
        gr.clear();
        int n = arr.size();
        
        gr.resize(n,vector<int>());
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                int cnt = 0;
                int m = arr[i].size();
                for(int k=0;k<m;k++){
                    if(arr[i][k]!=arr[j][k]) cnt++;
                }
                if(cnt==1){
                    gr[i].push_back(j);
                    gr[j].push_back(i);
                }

            }
        }
        int st = -1,en=-1;
        for(int i=0;i<n;i++){
            if(arr[i]==sw) {
                st=i;
                // break;
            }
            if(arr[i]==ew) en=i;
        }
        if(st==-1 || en == -1) return 0;

        queue<int>qu;
        qu.push(st);
        int ans = 1;
        vector<bool>visited(n,0);
        visited[st]=1;
        
        while(!qu.empty()){
            ans++;
            int s = qu.size();
            for(int i=0;i<s;i++){
                auto u = qu.front();
                
                qu.pop();
                for(auto v :gr[u]){
                    if(v==en){
                        return ans;
                    }
                    if(visited[v]) continue;
                    qu.push(v);
                    visited[v]=1;
                }

            }
        }
        return 0;
    }
};
