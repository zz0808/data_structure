class Solution {
public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        int f[days.back() + 1];
        f[0] = 0;
        int day_idx = 0;
        for (int i = 1; i <= days.back(); i++) {
            f[i] = INT_MAX;
            if (i != days[day_idx]) {
                f[i] = f[i - 1];
            } else {
                f[i] = min(f[i], (i - 1 >= 0 ? f[i - 1] : 0 )+ costs[0]);
                f[i] = min(f[i], (i - 7 >= 0 ? f[i - 7] : 0) + costs[1]);
                f[i] = min(f[i], (i - 30 >= 0 ? f[i - 30] : 0) + costs[2]);
                day_idx++;
            }
        }

        return f[days.back()];
    }
};
