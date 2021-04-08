class Solution {
public:
    /**
     * @param A: An array of Integer
     * @return: an integer
     */
    int longestIncreasingContinuousSubsequence(vector<int> &A) {
        // write your code here
        if (A.size() == 0) {
            return 0;
        }
        int m = A.size();
        // int f[m];
        // f[0] = 1;
        int now = 1, old = 1;
        int ans = 1;
        for (int i = 1; i < m; i++) {
            now = A[i] > A[i - 1] ? old + 1 : 1;
            ans = max(ans, now);
            old = now;
        }

        now = 1, old = 1;
        for (int i = 1; i < m; i++) {
            now = A[i] < A[i - 1] ? old + 1 : 1;
            ans = max(ans, now);
            old = now;
        }

        return ans;
    }
};
