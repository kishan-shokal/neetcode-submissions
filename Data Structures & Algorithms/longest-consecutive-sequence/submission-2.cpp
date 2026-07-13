class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(),nums.end());
        int ans = min(1,n);
        int i = 1;
        while(i<n){
            int tm = 1;
            while(i<n ){
                if(nums[i-1]+1==nums[i]){
                    tm++;
                    i++;
                }
                else if (nums[i]==nums[i-1]) i++;
                else break;
            }
            ans= max(ans,tm);
            i++;
            
        }
        return ans;
    }
};
