class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int n = nums.size();
        // 排序
        sort(nums.begin(), nums.end());
        // 初始化答案
        int bestSum = nums[0] + nums[1] + nums[2];

        for (int i = 0; i < n - 2; i++) {
            if (i > 0 && nums[i] == nums[i - 1])
                continue;

            int left = i + 1, right = n - 1;
            while (left < right) {
                // 因为只输出最接的的数值，所以不用去从
                int nowSum = nums[i] + nums[left] + nums[right];
                if (abs(target - nowSum) < abs(target - bestSum)) {
                    bestSum = nowSum;
                } 
                if (nowSum > target) {
                    right--;
                } else {
                    left++;
                }              
            }
        }

        return bestSum;
    }
};