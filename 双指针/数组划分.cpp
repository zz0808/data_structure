class Solution {
public:

    int partitionArray(vector<int> &nums, int k) {
        if (nums.size() == 0)
            return 0;
        int left = 0, right = nums.size() - 1;
        
        while (left < right) {
            while (left < right && nums[left] < k)
                left++;
            while (left < right && nums[right] >= k)
                right--;
            if (left < right) {
                swap(nums[left], nums[right]);
                left++, right--;
            }
        }
        
        if (nums[left] < k)
            return left + 1;
            
        return left;
    }
};