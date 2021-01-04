#include <unordered_set>

class Solution {
public:

    int maxLength(vector<int>& arr) {
        int i = 0, j = 0, ans = 0;
        if (arr.size() == 0) {
            return ans;
        }
        unordered_set<int> uset;
        for (int i = 0; i < arr.size(); i++) {
            while (j < arr.size() && uset.find(arr[j]) == uset.end()) {
                uset.insert(arr[j]);
                ans = max(ans, j - i + 1);
                j++;
            }
            if (j < arr.size())
                uset.erase(arr[i]);
            
        }
        return ans;   
    }
};