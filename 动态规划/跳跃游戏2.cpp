class Solution {
public:
    int jump(vector<int>& nums) {
        int f[nums.size()];
        f[0] = 0;

        for (int i = 1; i < nums.size(); i++) {
            f[i] = INT_MAX;
            for (int j = i - 1; j >= 0; j--) {
                if (f[j] != INT_MAX && nums[j] >= i - j) {
                    f[i] = min(f[i], f[j] + 1);
                }
            }
        }
        return f[nums.size() - 1];
    }
};
