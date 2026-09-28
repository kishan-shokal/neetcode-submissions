class Solution {

    double _myPow(double x,int n){
        if(n==0) return 1;
        if(x==0) return 0;
        double res = 1;
        while(n){
            if(n&1){
                res = res*x;
            }
            x=x*x;
            n/=2;
        }
        return res;


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
