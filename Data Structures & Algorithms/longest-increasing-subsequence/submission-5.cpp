class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int>v,dp(n,0);
        for(auto x:nums){
            int d = distance(v.begin(),lower_bound(v.begin(),v.end(),x));
            if(d>=v.size()) v.push_back(x);
            else v[d]=x;
        }
        return v.size();
    }
};
