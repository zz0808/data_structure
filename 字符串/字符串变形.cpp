class Transform {
public:
    string trans(string s, int n) {
        // write code here
        int i = 0, j = n - 1;
        for (i = 0, j = n - 1; i < j; i++, j--) {
            swap(s[i], s[j]);
        }
        i = 0, j = 0;
        s += " ";
        while (j < n + 1) {
            if (s[j] == ' ') {
                int x = i, y = j - 1;
                for ( ; x <= y; x++, y--) {
                    s[x] ^= 1 << 5;
                    if (x != y) {
                        s[y] ^= 1 << 5;
                        swap(s[x], s[y]);
                    }

                }
                i = j + 1;
            }
            j++;
        }
        s.pop_back();
        return s;
    }
};