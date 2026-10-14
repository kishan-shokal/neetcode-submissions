class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        unordered_map<char,int>mp1,mp2;
        for(auto x:s1) mp1[x]++;
        int n1=s1.size(),n2  = s2.size();
        int i = 0;
        if(n1>n2) return false;
        
        
        for(int j = 0;j<n2;j++){
            mp2[s2[j]]++;
            if(j-i+1<n1) continue;
            bool flag = true;
            for(auto p : mp1){
                if(p.second!=mp2[p.first]) {
                    flag = false;
                    break;
                }
            }
            if(flag) return true;
            mp2[s2[i]]--;
            i++;
        }
        return false;
        
    }
};
