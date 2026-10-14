class Solution {
public:

    bool check(unordered_map<char,int>&mps,unordered_map<char,int>&mpt){
        for(auto p:mpt){
            if(p.second>mps[p.first]) return false;
        }
        return true;
    }

    string minWindow(string s, string t) {
        int n = s.size(),m = t.size();
        unordered_map<char,int>mps,mpt;
        for(auto x:t) mpt[x]++;
        int j = 0,i = 0;
        int a = 0, b = n+1;
        while(j<n){
            while(j<n && !check(mps,mpt)) {
                mps[s[j]]++;
                j++;
            }
            while(i<j){

                mps[s[i]]--;
                if(!check(mps,mpt)){
                    mps[s[i]]++;
                    break;
                }
                i++;

            }
            if(check(mps,mpt) && j-i<b-a) {
                a= i;
                b= j;
            } 
            mps[s[i]]--;
            i++;

        }
        if(b==n+1) return "";
        return s.substr(a,b-a);

    }
};
