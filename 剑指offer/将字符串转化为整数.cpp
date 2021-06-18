class Solution {
public:
    int atoi(const char *str) {
        if (str == nullptr) {
            return 0;
        }
        int i = 0;
        while (str[i] == ' ') {
            i++;
        }
        int sign = 1;
        if (str[i] == '-') {
            sign = -1;
            i++;
        }
        if (str[i] == '+') {
            i++;
        }
        long long ans = 0;
        
        for (; isdigit(str[i]); i++) {
            ans = ans * 10 + str[i] - '0';
        }
        
        ans *= sign;
        
        if (ans >= INT_MAX) {
            return INT_MAX;
        }
        if (ans <= INT_MIN) {
            return INT_MIN;
        }
        
        return ans;
    }
};
