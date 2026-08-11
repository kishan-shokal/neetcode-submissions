class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int>v,dp(n,0);
        // for(auto x:nums){
            // int d = distance(nums.begin(),lower_bound(nums.begin(),nums.end(),x));
            // if(d==v.size()) v.push_back(x);
            // // else v[d]=x;
        // }
        // dp[0]=1;
        for(int i=0;i<n;i++){
            dp[i]=1;
            for(int j=i-1;j>=0;j--){
                if(nums[j]<nums[i]) {dp[i]=max(dp[i],dp[j]+1);}
            }
        }
        int ans = 0;
        for(auto x:dp ) ans=max(ans,x);
        return ans;
    }
};
