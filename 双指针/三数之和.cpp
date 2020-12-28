class Solution {
public:
 
    vector<vector<int>> threeSum(vector<int> &numbers) {
        vector<vector<int>> ans;
        if (numbers.size() < 0)
            return ans;
        
        // n数之和问题，先排序
        sort(numbers.begin(), numbers.end());
           
        for (int i = 0; i < numbers.size(); i++) {
            
            if (i > 0 && numbers[i - 1] == numbers[i])
                continue;
                
            int temp = 0 - numbers[i], left = i + 1, right = numbers.size() - 1;
            while (left < right) {
                if (numbers[left] + numbers[right] == temp) {
                    ans.push_back({numbers[i], numbers[left], numbers[right]});
                    left++, right--;
                    while (left < right && numbers[left] == numbers[left - 1])
                        left++;
                    while (left < right && numbers[right] == numbers[right + 1])
                        right--;
                } else if (numbers[left] + numbers[right] < temp) {
                    left++;
                } else {
                    right--;
                }
            }
        }
        
        return ans;
    }
};