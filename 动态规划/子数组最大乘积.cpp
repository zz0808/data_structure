// 计算连续最大乘积

class Solution {
public:
    double maxProduct(vector<double> arr) {
        
        int n = arr.size();
//         double f1[n + 1], f2[n + 1];
        double now1 = arr[0], now2 = arr[0], old1 = arr[0], old2 = arr[0];
//         f1[1] = arr[0], f2[1] = arr[0];
        double ans = arr[0];
        for (int i = 2; i <= n; i++) {
//             f1[i] = max(arr[i - 1], max(f1[i - 1] * arr[i - 1], f2[i - 1] * arr[i - 1]));
//             f2[i] = min(arr[i - 1], min(f1[i - 1] * arr[i - 1], f2[i - 1] * arr[i - 1]));
//             ans = max(ans, f1[i]);
            now1 = max(arr[i - 1], max(old1 * arr[i - 1], old2 * arr[i - 1]));
            now2 = min(arr[i - 1], min(old1 * arr[i - 1], old2 * arr[i - 1]));
            old1 = now1, old2 = now2;
            ans = max(ans, now1);            
        }
        
        return ans;
    }
};