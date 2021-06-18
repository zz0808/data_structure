class Solution {
public:
    vector<int> findElement(vector<vector<int> > mat, int n, int m, int x) {
        // write code here
        int curtRow = n - 1, curtCol = 0;
        
        while (curtRow >= 0 && curtCol < m) {
            if (mat[curtRow][curtCol] > x) {
                curtRow--;
            } else if (mat[curtRow][curtCol] < x) {
                curtCol++;
            } else {
                return vector<int>{curtRow, curtCol};
            }
        }
        
        return vector<int>{-1, -1};
    }
};
