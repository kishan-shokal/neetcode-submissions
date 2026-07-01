class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        map<int,int>mp;
        for(auto x:nums)mp[x]++;
        vector<pair<int,int>>frq;
        for(auto p:mp) frq.push_back({p.second,p.first});
        sort(frq.begin(),frq.end(),greater<pair<int,int>>());
        vector<int>ans;
        for(int i=0;i<k;i++) ans.push_back(frq[i].second);
        return ans;
    }
};
