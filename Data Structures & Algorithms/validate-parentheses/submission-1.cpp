class Solution {
public:
    bool isValid(string s) {
        stack<char>st;
        for(auto c:s){
            if(string("([{").find(c) != string::npos){
                st.push(c);
            }
            else{
                if(st.size()==0) return false;
                auto tp = st.top();
                if((tp == '(' && c ==')') ||
                    (tp == '[' && c ==']') ||
                    tp == '{' && c =='}'
                ){
                    st.pop();
                }
                else return false;
            }
        }
        return st.size()==0;
    }
};
