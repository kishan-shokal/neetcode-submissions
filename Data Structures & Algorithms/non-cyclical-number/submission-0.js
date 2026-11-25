
class Solution {
    /**
     * @param {number} n
     * @return {boolean}
     */
    isHappy(n) {
        const mp = new Map();

        while (!mp.has(n)) {
            mp.set(n, true);

            let sm = 0;

            while (n > 0) {
                let digit = n % 10;
                sm += digit * digit;
                n = Math.floor(n / 10);
            }

            n = sm;
        }

        return n == 1;
    }
}
