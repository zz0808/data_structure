class Solution {
public:
    vector<vector<string>> partition(string s) {
        // 所有的切割问题都是组合问题
        // n个字母的切割问题，就是n-1个数字的组合问题
    	vector<vector<string>> ans;
    	if (s.length() == 0)
    		return ans;

    	vector<string> cur_set;


    }

    void helper(string& s, vector<vector<string>>& ans, vector<string>& cur_set, int start_index) {

    	if (start_index == s.length()) {
    		ans.emplace_back(cur_set);
    		return;
    	}

    	for (int i = start_index; i < s.length(); i++) {
    		string substr = s.substr(start_index, i - start_index + 1);
    		if (!isPalidrome(substr))
    			continue;;
    		cur_set.emplace_back(substr);
    		helper(s, ans, cur_set, i + 1);
    		cur_set.pop_back();
    	}

    }

    bool isPalidrome(string s) {
    	for (int i = 0, j = s.length() - 1; i < j; i++, j--) {
    		if (s[i] != s[j])
    			return false;
    	}
    	return true;
    }
};