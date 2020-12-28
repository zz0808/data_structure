#include <unordered_map>

class Solution {
public:
    /**
     * return topK string
     * @param strings string字符串vector strings
     * @param k int整型 the k
     * @return string字符串vector<vector<>>
     */
    vector<vector<string>> topKstrings(vector<string>& strings, int k) {
        // write code here
        vector<vector<string>> ans;
        if (strings.size() < k)
            return ans;
        // 建立哈希表，存放每个字符串出现的次数
        unordered_map<string, int> hash;
        
        for (const auto& str : strings) {
            hash[str]++;
        }
        // 最小堆的比较方式
        auto cmp = [](const pair<string, int>& lhs, const pair<string, int>& rhs) {
            if (lhs.second != rhs.second)
                return lhs.second > rhs.second;
            return lhs.first < rhs.first;
        };
        // 使用最小堆
        priority_queue<pair<string, int>, vector<pair<string, int>>, decltype(cmp)> minHeap(cmp);
        
        auto iter = hash.begin();
        
        while (iter != hash.end()) {
            
            minHeap.emplace(*iter);
            if (minHeap.size() > k) {
                minHeap.pop();
            }
            iter++;
        }
        
        while (!minHeap.empty()) {
            auto p = minHeap.top();
            minHeap.pop();
            ans.push_back({p.first, to_string(p.second)});
        }
        
        reverse(ans.begin(), ans.end());
        
        return ans;
        
    }
};