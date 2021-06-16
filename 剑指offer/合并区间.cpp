/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
class Solution {
public:
    vector<Interval> merge(vector<Interval> &intervals) {
        vector<Interval> ans;
        auto cmp = [](const Interval& a, const Interval& b) {
	    	if(a.start != b.start){ 
				return a.start< b.start;
			}
	    	return a.end < b.end;
		};
		
        sort(intervals.begin(),intervals.end(),cmp);
        int m = intervals.size();
        if(m == 0) {
        	return intervals;	
		}
		
        for(int i = 1 ; i < m; i++) {
			if (intervals[i].start <= intervals[i - 1].end) {
				// 合并区间
				intervals[i].start = min(intervals[i].start, intervals[i - 1].start);
				intervals[i].end = max(intervals[i].end, intervals[i - 1].end); 
			} else {
				ans.push_back(intervals[i - 1]);
			}
        }
        ans.push_back(intervals[m - 1]);
        return ans;
 
    }
};