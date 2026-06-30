class Solution {
    vector<vector<int>>ans;
public:
    void f(vector<int>&arr,int ind ,vector<int>v={}){
        if(ind==arr.size()) {
            ans.push_back(v);
            return ;
        }
        v.push_back(arr[ind]);
        f(arr,ind+1,v);
        v.pop_back();
        
        f(arr,ind+1,v);
        

    }
    vector<vector<int>> subsets(vector<int>& nums) {
        f(nums,0);
        return ans;
    }
};
