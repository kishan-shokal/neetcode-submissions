class Solution {

    double _myPow(double x,int n){
        return pow(x,n);
    }
public:
    double myPow(double x, int n) {
        auto ans = _myPow(x,abs(n));
        if(n<0){
            if(ans==0){
                return (double) 0;
            }
            ans = 1/ans;
        }
        return ans;
    }
};
