class Solution {
public:
    vector<vector<int>>ans;
    void dfs(vector<int>&nums,int ind){
        if(ind==nums.size()){
            ans.push_back(nums);
            return ;
        }
        for(int i=ind;i<nums.size();i++){
            swap(nums[ind],nums[i]);
            dfs(nums,ind+1);
            swap(nums[ind],nums[i]);
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        dfs(nums,0);
        return ans;
    }
};
