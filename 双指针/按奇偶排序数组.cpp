// 给数组A，使得所有奇数在偶数后面
// 相向双指针

class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& A) {
        int i = 0, j = A.size() - 1;

        while (i < j) {
            while (i < j && A[i] % 2 == 0)
                i++;
            while (i < j && A[j] % 2 == 1)
                j--;
            if (i < j) {
                swap(A[i], A[j]);
            }
        }

        return A;
    }
};