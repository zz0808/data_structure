class Solution {
public:
    vector<vector<int> > threeSum(vector<int> &num) {
        vector<vector<int>> ans;
        
        if (num.size() < 3) {
            return ans;
        }
        sort(num.begin(), num.end());
        for (int i = 0; i < num.size() - 2; i++) {
            if (i > 0 && num[i] == num[i - 1]) {
                continue;
            }
            int start = i + 1, end = num.size() - 1;
            while (start < end) {
                int target = num[start] + num[end] + num[i];
                if (target > 0) {
                    end--;
                } else if (target < 0) {
                    start++;
                } else {
                    ans.push_back({num[i], num[start], num[end]});
                    start++, end--;
                    while (num[start] == num[start - 1]) {
                        start++;
                    }
                    while (num[end] == num[end + 1]) {
                        end--;
                    }
                }
            }
        }
        return ans;
    }
};
