class Solution {
public:
    int maxArea(vector<int>& heights) {
        int n = heights.size();
        // vector<int>sufMax(n);
        // sufMax[n-1]=heights[n-1];
        // for(int n-2;i>=0;i--) sufMax[i] = max(sufMax[i+1],heights[i]);
        int ans = 0;
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                int tm = min(heights[i],heights[j])*(j-i);
                ans = max(ans,tm);
            }
        }
        return ans;
    }
};
