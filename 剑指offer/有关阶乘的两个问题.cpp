class Solution {
public:
    /**
     * the number of 0
     * @param n long长整型 the number
     * @return long长整型
     */
    long long thenumberof0(long long n) {
        long long ans = 0;
        while (n >= 5) {
            ans += n / 5;
            n /= 5;
        }
        return ans;
    }
};

