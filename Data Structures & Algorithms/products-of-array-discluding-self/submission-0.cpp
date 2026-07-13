class Solution {
public:
    vector<int> productExceptSelf(vector<int>& arr) {
        int n = arr.size();
        vector<int> pre(n+1,1),suf(n+1,1),ans;
        for(int i=1;i<=n;i++) pre[i] = pre[i-1]*arr[i-1];
        for(int i=n-1;i>=0;i--) suf[i] = suf[i+1]*arr[i];
        for(int i=1;i<=n;i++){
            int tm = pre[i-1]*suf[i];
            ans.push_back(tm);
        }
        return ans;

    }
};
