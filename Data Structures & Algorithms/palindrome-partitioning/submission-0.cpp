class Solution {
public:
    vector<vector<string>>ans;
    int n ;
    bool checkPelindrome(string st){
        int i = 0,j=st.size()-1;
        while(i<j){
            if(st[i]!=st[j]) return false;
            i++;j--;
        }
        return true;
    }
    void f(string st,int ind,string sub,vector<string>v){
        if(ind == n){
            cout<<sub<<endl;
            if(checkPelindrome(sub)) {v.push_back(sub);ans.push_back(v);v.pop_back();};
            return ;
        }
        f(st,ind+1,sub+st[ind],v);
        if(sub!="" && checkPelindrome(sub)){
            v.push_back(sub);
            f(st,ind,"",v);
            v.pop_back();
        }
        return ;



    }
    vector<vector<string>> partition(string s) {
        ans.clear();
        n = s.size();
        vector<string>v;
        f(s,0,"",v);
        return ans;
    }
    
};
