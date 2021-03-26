#include <unordered_map>
class Solution {
public:
    /**
     * return topK string
     * @param strings string字符串vector strings
     * @param k int整型 the k
     * @return string字符串vector<vector<>>
     */
    vector<vector<string> > topKstrings(vector<string>& strings, int k) {
        // write code here
        vector<vector<string>> ans;
        if (k > strings.size()) {
            return ans;
        }
        unordered_map<string, int> hash;

        for (const string& str : strings) {
            hash[str]++;
        }
        auto cmp = [](const pair<string, int>& lhs, const pair<string, int>& rhs) {
            if (lhs.second != rhs.second) {
                return lhs.second > rhs.second;
            }
            return lhs.first < rhs.first;
        };
        priority_queue<pair<string, int>, vector<pair<string, int>>, decltype(cmp)> min_heap(cmp);

        for (auto iter = hash.begin(); iter != hash.end(); iter++) {
            min_heap.push(*iter);
            if (min_heap.size() > k) {
                min_heap.pop();
            }
        }

        while (!min_heap.empty()) {
            auto curt = min_heap.top();
            min_heap.pop();
            ans.insert(ans.begin(), {curt.first, to_string(curt.second)});
        }

        return ans;
    }
};
