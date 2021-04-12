class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int m = nums.size();
        if (m == 0) {
            return 0;
        }
        int ans = INT_MAX;
        int sum = 0;
        int i, j = 0;
        for (i = 0; i < m; i++) {
            while (j < m && sum < target) {
                sum += nums[j];
                j++;
            }
            if (sum >= target) {
                ans = min(ans, j - i);
                sum -= nums[i];
            }
        }

        return ans == INT_MAX ? 0 : ans;
    }
};
