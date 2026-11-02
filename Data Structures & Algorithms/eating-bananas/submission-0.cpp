class Solution {
public:
    int calculateTime(vector<int>&arr,int k){
        int time = 0;
        for(auto x:arr){
            time+=(x+k-1)/k;
        }
        return time;
    }
    int minEatingSpeed(vector<int>& arr, int h) {
        int start = 1,end = INT_MAX;
        int ans = -1;
        while(start<=end){
            int mid = start + (end-start)/2;
            int time = calculateTime(arr,mid);
            if(time>h){
                start = mid+1;
            }
            else {
                ans = mid;
                end=mid-1;
            }
        }
        return ans;
    }
};
