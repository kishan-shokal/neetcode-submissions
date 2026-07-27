class Solution {
public:
    int n;
    vector<int>nums;

    vector<vector<vector<int>>>dp;

    int f(int ind,bool prev,bool first){
        if(ind==n) return 0;
        if(dp[ind][prev][first]!=-1) return dp[ind][prev][first];
        int include=0,exclude=0;
        // if(ind==0)
        exclude = f(ind+1,false,first);
        if(ind==0) first=true;
        if(!prev && ((ind!=n-1 || ind==0) || !first)){
            include = f(ind+1,true,first)+nums[ind];
        }
        return  dp[ind][prev][first]=max(include,exclude);

    }
    int rob(vector<int>& nums) {
        dp.clear();
        n = nums.size();
        dp.resize(
            n,
            vector<vector<int>>(
                2,
                vector<int>(2, -1)
            )
        );
        
        this->nums = nums;
        int ans = f(0,0,0);
        return ans;
    }
};
