class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        
        int start = 0, end = arr.size() - 1;
       // 下降、上升、峰底都去掉 
        while (start + 1 < end) {
            int mid = start + (end - start) / 2;
            if (arr[mid] >= arr[mid + 1]) {
                end = mid;
            } else if ( arr[mid] <= arr[mid + 1]) {
                start = mid;
            } 
        }

        return arr[start] > arr[end] ? start : end;
    }
};
