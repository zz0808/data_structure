class Solution {
public:
    bool canJump(vector<int>& nums) {
        bool f[nums.size()];
        f[0] = true;

        for (int i = 1; i < nums.size(); i++) {
            f[i] = false;
            for (int j = i - 1; j >= 0; j--) {
                if (f[j] && nums[j] >= i - j) {
                    f[i] = true;
                    break;
                }
            }
        }

        return f[nums.size() - 1];
    }
};
