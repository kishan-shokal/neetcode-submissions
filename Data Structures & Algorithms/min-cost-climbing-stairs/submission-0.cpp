class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        cost.push_back(0);
        int n = cost.size();

        int a=0,b=0;
        for(int i=1;i<n;i++){
            int c = a + cost[i-1];
            if(i-2>=0){
                c = min(c,b+cost[i-2]);
            }
            b=a;
            a=c;
        }
        int ans = a;
        a=0;b=0;
        for(int i=2;i<n;i++){
            int c = a + cost[i-1];
            if(i-2>=0){
                c = min(c,b+cost[i-2]);
            }
            b=a;
            a=c;
        }
        ans =min(ans,a);
        return ans;

    }
};
