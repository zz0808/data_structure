class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
    
        unordered_set<string> uset(wordList.begin(), wordList.end());
        if (uset.find(endWord) == uset.end()) 
            return 0;
        // 变换最少次数问题，首先使用广度优先搜索
        // hit 的临接边 ait、bit 等等，
        unordered_set<string> visit;

        queue<string> q;
        q.emplace(beginWord);
        visit.insert(beginWord);
        int min_distance = 1;
        while (!q.empty()) {
            int sz = q.size();
            for (int i = 0; i < sz; i++) {
                string temp = q.front();
                q.pop();
                for (int j = 0; j < temp.length(); j++) {
                    char c = temp[j];
                    for (int k = 0; k < 26; k++) {
                        if (c == k + 'a')
                            continue;
                        temp[j] = k + 'a';
                        if (temp == endWord) {
                            return min_distance + 1;
                        }
                        if (uset.find(temp) != uset.end() && visit.find(temp) == visit.end()) {
                            visit.insert(temp);
                            q.emplace(temp);
                        }
                    }
                    temp[j] = c;
                }
            }
            min_distance++;
        }


        return 0;
    }
};