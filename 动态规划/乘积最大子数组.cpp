class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        // int f[n], g[n];
        int f, g;
        f = g = nums[0];
        int ans = nums[0];
        for (int i = 1; i < n; i++) {
            int f1 = max(nums[i], max(f * nums[i], g * nums[i]));
            int g1 = min(nums[i], min(f * nums[i], g * nums[i]));
            f = f1, g = g1;
            ans = max(ans, f);
        }

        return ans;
    }
};
