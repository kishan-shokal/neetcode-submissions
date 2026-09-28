#define ll long long
class Solution {
public:
    int mySqrt(int x) {
        ll st = 0 ,en=x;
        int ans=-1;
        while(st<=en){
            ll mid = (st+en)/2;
            ll sq = mid*mid;
            // if(sq==x) return mid;
            if(sq<=x){
                ans = mid;
                st= mid+1;
            }
            else en=mid-1;
        }
        return ans;
    }

};