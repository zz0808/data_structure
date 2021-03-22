class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     * 
     * @param array int整型vector 
     * @return int整型vector
     */
    vector<int> FindNumsAppearOnce(vector<int>& array) {
        // write code here
        vector<int> ans(2);
        int bitxor = 0;
        for (int x : array) {
            bitxor ^= x;
        }
        int diff = 1;
        while (!(bitxor & diff)) {
            diff <<= 1;
        }
        
        for (int x : array) {
            if (!(diff & x)) {
                ans[0] ^= x;
            } else {
                ans[1] ^= x;
            }
        }
        if (ans[0] > ans[1]) {
            swap(ans[0], ans[1]);
        }
        return ans;
    }
};
