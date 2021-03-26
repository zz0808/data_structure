class Solution {
public:
    /**
     * retrun the longest increasing subsequence
     * @param arr int整型vector the array
     * @return int整型vector
     */
    vector<int> LIS(vector<int>& arr) {
        int n = arr.size();
        if (n <= 1)
            return arr;
        vector<int> ans;
        vector<int> maxlen;
        ans.push_back(arr[0]);
        maxlen.push_back(1);
        
        for (int i = 1; i < arr.size(); i++) {
            if (arr[i] > ans.back()) {
                ans.push_back(arr[i]);
                maxlen.push_back(ans.size());
            } else {
                int pos = lower_bound(ans.begin(), ans.end(), arr[i]) - ans.begin();
                ans[pos] = arr[i];
                maxlen.push_back(pos + 1);
            }
        }
        
        int last_len = ans.size();
        for (int i = arr.size() - 1, j = last_len; j > 0; i--) {
            if (maxlen[i] == j) {
                ans[--j] = arr[i];
                
            }
        }
        
        return ans;
    }
};
