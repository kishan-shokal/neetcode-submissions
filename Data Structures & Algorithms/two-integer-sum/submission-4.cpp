class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int i=0,j=nums.size()-1;
        vector<pair<int,int>> arr;
        for(int i =0;i<=j;i++){
            arr.push_back({nums[i],i});
        }
        sort(arr.begin(),arr.end());
        while(i<j){
            int sm = arr[i].first+arr[j].first;
            if(sm==target) {
                vector<int> ans = {arr[i].second,arr[j].second};
                sort(ans.begin(),ans.end());
                return ans;
            }
            if(sm<target) i++;
            else j--;
        }
        return {-1,-1};
    }
    
};
