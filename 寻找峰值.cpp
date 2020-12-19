class Solution {
public:
    int findPeakElement(vector<int>& nums) {
    	
    	int start = 0, end = nums.size() - 1;
    	while (start + 1 < end) {
    		int mid = start + (end - start) / 2;
    		// mid 最多也不会到num.size() - 1的位置，所以nums[mid + 1]保证不会越界

    		if (nums[mid] < nums[mid + 1]) { // 上升、峰底
    			start = mid;
    		} else if (nums[mid] > nums[mid + 1]) { // 下降
    			end = mid;
    		} 
    	}

    	return nums[start] > nums[end] ? start : end;
    }
};