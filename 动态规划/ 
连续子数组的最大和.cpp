class Solution {
public:
    int FindGreatestSumOfSubArray(vector<int> array) {
        int n = array.size();
        int old = 0, now = 0;
        int ans = INT_MIN;
        for (int i = 1; i <= n; i++) {
            now = max(old + array[i - 1], array[i - 1]);
            ans = max(now, ans);
            old = now;
        }
        
        return ans;
    }
};
// 水题