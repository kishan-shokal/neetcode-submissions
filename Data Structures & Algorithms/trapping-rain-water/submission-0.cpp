class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        vector<int>sufMax(n);
        sufMax[n-1]=height[n-1];
        for(int i=n-2;i>=0;i--) sufMax[i]=max(sufMax[i+1],height[i]);
        int ans = 0;
        int prMax=0;
        for(int i=0;i<n;i++){
            ans+=max(0,min(prMax,sufMax[i])-height[i]);
            prMax=max(prMax,height[i]);

        }
        return ans;
    }
};
