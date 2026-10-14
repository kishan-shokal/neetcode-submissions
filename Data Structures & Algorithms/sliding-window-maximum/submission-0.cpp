class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& arr, int k) {
        int n = arr.size();
        deque<int>dq;
        vector<int>ans;
        for(int i = 0;i<n;i++){
            while(!dq.empty() && arr[dq.back()]<arr[i]){
                dq.pop_back();
            }
            dq.push_back(i);
            if(i+1<k) continue;
            while(!dq.empty() && dq.front()<=i-k) {
                dq.pop_front();
            }
            ans.push_back(arr[dq.front()]);
        }
        return ans;

    }
};
