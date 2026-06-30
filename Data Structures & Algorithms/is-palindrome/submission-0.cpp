class Solution {
public:
    bool isPalindrome(string s) {
        string st = s;
        transform(st.begin(), st.end(), st.begin(), ::tolower);
        int i = 0 ,j = st.size()-1;
        while(i<j){
            if((st[i]<'a' || st[i]>'z') && (st[i]<'0' || st[i]>'9')) i++;
            else if((st[j]<'a' || st[j]>'z') && (st[j]<'0' || st[j]>'9')) j--;
            else {
                if(st[i]==st[j]){
                    i++;
                    j--;
                }
                else return false;
            }

        }
        return true;
        
    }
};
