class Solution {
public:

    vector<int> twoSum(vector<int> &numbers, int target) {
        
        vector<int> ans;
        if (numbers.size() < 2)
            return ans;
        int n = numbers.size();
        
        // 使用哈希表，key : target - numbers[i], value : i
        unordered_map<int, int> hash;
        hash[target - numbers[0]] = 0;
        
        for (int i = 1; i < n; i++) {
            if (hash.find(numbers[i]) != hash.end()) {
                ans = {hash[numbers[i]], i};
                break;
            } else {
                hash[target - numbers[i]] = i;
            }
        }
        
        return ans;
    }
};