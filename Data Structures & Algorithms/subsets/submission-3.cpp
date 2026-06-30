class Solution {
    vector<vector<int>> ans;

public:
    void f(vector<int>& arr, int ind, vector<int>& v) {
        if (ind == arr.size()) {
            ans.push_back(v);
            return;
        }
        f(arr, ind + 1, v);
        v.push_back(arr[ind]);
        f(arr, ind + 1, v);
        v.pop_back();
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        ans.clear(); 
        vector<int> v;
        f(nums, 0, v);
        return ans;
    }
};