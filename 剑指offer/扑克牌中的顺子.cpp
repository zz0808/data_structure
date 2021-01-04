class Solution {
public:
    bool isStraight(vector<int>& nums) {
        if (nums.size() < 5)
            return false;
        sort(nums.begin(), nums.end());
        int zeros = 0;
        for (int i = 0; i < 5; i++) {
            if (nums[i] == 0) {
                zeros++;
            }
            if (i > 0 && nums[i] != 0 && nums[i - 1] != 0) {
                int temp = zeros - (nums[i] - nums[i - 1] - 1);
                if (temp < 0 || temp > zeros) {
                    return false;
                }
                zeros = temp;
            }

        }

        return true;
    }
};