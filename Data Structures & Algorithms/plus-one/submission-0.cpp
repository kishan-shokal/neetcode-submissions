class Solution {
public:
    vector<int> plusOne(vector<int>& arr) {
        reverse(arr.begin(),arr.end());
        int c=1;
        for(auto & x:arr){
            x=x+c;
            c = x/10;
            x%=10;
        }
        if(c) arr.push_back(c);
        reverse(arr.begin(),arr.end());
        return arr;
    }
};
