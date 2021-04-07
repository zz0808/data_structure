class Solution {
public:
    /**
     * 旋转字符串
     * @param A string字符串 
     * @param B string字符串 
     * @return bool布尔型
     */
    bool solve(string A, string B) {
        // write code here
        // A=‘youzan’，B=‘zanyou’
        int m = A.length(), n = B.length();
        if (m != n) {
        	return false;
        }
        for (int i = 0; i < m; i++) {
        	if (A[i] != B[0] || A[0] != B[m - i]) {
        		continue;
        	}
        	bool flag = true;
        	for (int j = 0; j < i; j++) {
        		if (A[j] != B[m - i + j]) {
        			flag = false;
        			break;
        		}
        	}
        	for (int j = i; j < m; j++) {
        		if (A[j] != B[j - i]) {
        			flag = false;
        			break;
        		}
        	}
        	if (flag == true) {
        		return true;
        	}
        }

        return false;
    }
};
