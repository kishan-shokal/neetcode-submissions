class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int ans = 0;
        int mi = INT_MAX;
        for (auto & price : prices){
            ans = max(ans,price-mi);
            mi = min(mi,price);
        }
        return ans;

    }
};
