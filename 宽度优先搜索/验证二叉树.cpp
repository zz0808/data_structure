class Solution {
public:
    bool validateBinaryTreeNodes(int n, vector<int>& leftChild, vector<int>& rightChild) {

        vector<int> indgrees(n, 0);        
        for (int i = 0; i < n; i++) {
            if (leftChild[i] != -1)
                indgrees[leftChild[i]]++;
            if (rightChild[i] != -1)
                indgrees[rightChild[i]]++;
        }
        int root = -1;
        for (int i = 0; i < n; i++) {
            if (indgrees[i] == 0) {
                root = i;
                break;
            }
        }
        // 如果所有节点都有入度，则说明有环
        if (root == -1)
            return false;
        queue<int> q;
        unordered_set<int> uset;
        q.emplace(root);
        uset.insert(root);
        // 使用队列遍历所有节点，如果某个节点没遍历多次，则说明有环
        while (!q.empty()) {
            int node = q.front();
            q.pop();
            if (leftChild[node] != -1) {
                if (uset.count(leftChild[node]))
                    return false;
                q.emplace(leftChild[node]);
                uset.insert(leftChild[node]);
            }
            if (rightChild[node] != -1) {
                if (uset.count(rightChild[node]))
                    return false;
                q.emplace(rightChild[node]);
                uset.insert(rightChild[node]);               
            }
        }

        return uset.size() == n;
    }
};