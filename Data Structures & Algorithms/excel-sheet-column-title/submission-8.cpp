class Solution {
public:
    string convertToTitle(int n) {
        string ans;

        while (n > 0) {
            n--;

            int r = n % 26;

            char ch = 'A' + r;

            ans += ch;

            n /= 26;
        }

        reverse(ans.begin(), ans.end());

        return ans;
    }
};