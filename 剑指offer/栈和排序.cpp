#include <iostream>
#include <vector>
#include <stack>
using namespace std;

class Solution {
public:
    /**
     * 栈排序
     * @param a int整型一维数组 描述入栈顺序
     * @param aLen int a数组长度
     * @return int整型vector
     */
    vector<int> solve(int* a, int aLen) {
        vector<int> ans;
        if (aLen <= 0) {
            return ans;
        }
        vector<int> cur_max(aLen + 1, 0);
        cur_max[aLen] = INT_MAX;
        
        int maxn = 0;
        for (int i = aLen - 1; i >= 0; i--) {
            maxn = max(maxn, a[i]);
            cur_max[i] = maxn;
        }
        for (int i = 0; i < aLen; i++) {
            stk.push(a[i]);
            while (!stk.empty() && stk.top() > cur_max[i + 1]) {
                ans.push_back(stk.top());
                stk.pop();
            }
        }
        while (!stk.empty()) {
            ans.push_back(stk.top());
            stk.pop();
        }
        return  ans;
    }
    
private:
    stack<int> stk;
};

