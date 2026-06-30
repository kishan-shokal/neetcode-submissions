class Solution {
public:
    vector<int> twoSum(vector<int>& arr, int target) {
        int i=0,j=arr.size()-1;
        while(i<j){
            int sm = arr[i]+arr[j];
            if(sm==target) return {i+1,j+1};
            if(sm<target) i++;
            else j--;
        }
        return {-1,-1};
    }
};
