class Solution {
public:
    int search(vector<int>& nums, int target) {

    	int start = 0, end = nums.size() - 1;

           /
          /
    	 /	
    	/
    --------------	/
    	           /
    	          /  
    	// 以num[start]为基准，大于等于这个值则应该在左上方找，否则在右下方找，这样就扔掉了一半
    	// 
    	while (start + 1 < end) {

    		int mid = start + (end - start) / 2;

    		if (nums[start] <= target) {
    			if (nums[start] <= target && target <= nums[mid]) {
    				end = mid;
    			} else {
    				start = mid;
    			}
    		} else {
    			if (nums[mid] <= target && target <= nums[end]) {
    				start = mid;
    			} else {
    				end = mid;
    			}
    		}
    	}

    	if (nums[start] == target)
    		return start;
    	if (nums[end] == target)
    		return end;
    	return -1;
     }
};