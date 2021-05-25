class ConnectingGraph3 {
public:
    /**
     * @param a: An integer
     * @param b: An integer
     * @return: nothing
     */
     ConnectingGraph3(int n) {
        // initialize your data structure here.
        count = n;
        father.resize(n + 1);
        for (int i = 1; i <= n; i++) {
            father[i] = i;
        }
    }
    void connect(int a, int b) {
        // write your code here
        int root_a = find(a);
        int root_b = find(b);
        if (root_a != root_b) {
            father[root_a] = root_b;
            count--;
        }
    }
    int find(int x) {
        if (father[x] == x) {
            return x;
        }
        return father[x] = find(father[x]);
    }
    /**
     * @return: An integer
     */
    int query() {
        // write your code here
        return count;
    }
private:
    int count;
    vector<int> father;
};
