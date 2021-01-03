// 三种颜色分别用0，1，2表示，排列后每种颜色在一起，不同的颜色有序
// 三指针

class Solution {
public:
    void sortColors(vector<int>& nums) {
        int i = 0, j = nums.size() - 1; // i左边都是0，j右边都是2
        int k = 0;
        while (k <= j) {
            if (nums[k] == 1) { // 略过1，因为0，2分别在两端，1自然在中间部分
                k++; 
            } else if (nums[k] == 0) { 
                swap(nums[i], nums[k]);
                i++, k++; // 遇到0，i++, 位置上k>=i, 否则k会在0的部分，而i是什么不确定，会重复交换导致错误结果
            } else if (nums[k] == 2) {
                swap(nums[j], nums[k]);
                j--;
            }
        }
    }
};