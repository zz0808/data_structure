class Solution {
public:
    /**
     * pick candy
     * @param arr int整型vector the array
     * @return int整型
     */
    int candy(vector<int>& arr) {
        // write code here
        if (arr.size() == 0) {
            return 0;
        }
        int down = 0, up = 0, ans = 1, peak = 1;
        for (int i = 1; i < arr.size(); i++) {
            ans++;
            if (arr[i] > arr[i - 1]) {
                up++;
                down = 0;              
                ans += up;
                peak = up + 1;
            } else if (arr[i] == arr[i - 1]) {
                up = 0;
                down = 0;
                peak = 1;
            } else {
            	up = 0;
                ans += down;
                down++;
                if (down >= peak) {
                    ans++;
                }
            }
        }
        return ans;
    }
};
