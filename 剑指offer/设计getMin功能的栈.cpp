class Solution {
public:
    /**
     * return a array which include all ans for op3
     * @param op int整型vector<vector<>> operator
     * @return int整型vector
     */
    vector<int> getMinStack(vector<vector<int> >& op) {
        // write code here
        vector<int> ans;
        if (op.size() == 0) {
            return ans;
        }
        for (auto& o : op) {
            if (o[0] == 1) {
                push(o[1]);
            } else if (o[0] == 2) {
                pop();
            } else if (o[0] == 3) {
                ans.push_back(get_min());
            }
        }
        return ans;
        
    }
    void push(int val) {
        value.push(val);
        if (curt_min.empty()) {
            curt_min.push(val);
        } else {
            if (curt_min.top() > val) {
                curt_min.push(val);
            } else {
                curt_min.push(curt_min.top());
            }
        }
    }
    
    void pop() {
        value.pop();
        curt_min.pop();
    }
    
    int get_min() {
        return curt_min.top();
    }
    
private:
    stack<int> value;
    stack<int> curt_min;
};
