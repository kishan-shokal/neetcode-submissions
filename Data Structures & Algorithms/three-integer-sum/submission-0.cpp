class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& arr) {
        sort(arr.begin(),arr.end());
        vector<vector<int>>ans;
        int n = arr.size();
        for(int i=0;i<n;i++){
            if(i!=0 && arr[i]==arr[i-1]) continue;
            int j = i+1;
            int k=n-1;
            while(j<k){
                int sm = arr[i]+arr[j]+arr[k];
                if(sm==0){
                    ans.push_back({arr[i],arr[j],arr[k]});
                    j++;
                    while(j<k && arr[j]==arr[j-1]) j++;
                }
                else if(sm<0) j++;
                else k--;
            }
        }
        return ans;
    }
};
