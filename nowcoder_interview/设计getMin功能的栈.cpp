class Solution {
public:
    /**
     * return a array which include all ans for op3
     * @param op int整型vector<vector<>> operator
     * @return int整型vector
     */
    vector<int> getMinStack(vector<vector<int> >& op) {
        vector<int> ans;
        for (auto v : op) {
            if (v[0] == 1) { // push
                push(v[1]);
            } else if (v[0] == 2) { // pop
                pop();
            } else if (v[0] == 3) { // get min
                ans.emplace_back(get_min());
            }
        }
        return ans;
    }
    void push(int v) {
        if (data.empty()) {
            min_in_data.emplace(v);
        } else {
            if (min_in_data.top() < v) {
                min_in_data.emplace(min_in_data.top());
            } else {
                min_in_data.emplace(v);
            }
        }
        data.emplace(v);
    }
    void pop() {
        data.pop();
        min_in_data.pop();
    }
    int get_min() {
        return min_in_data.top();
    }
private:
    stack<int> data;
    stack<int> min_in_data;
};