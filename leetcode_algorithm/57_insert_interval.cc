#include <iostream>
#include <vector>
using namespace std;


// Definition for an interval.
struct Interval {
    int start;
    int end;
    Interval() : start(0), end(0) {}
    Interval(int s, int e) : start(s), end(e) {}
};

class Solution {
public:
    vector<Interval> insert(vector<Interval>& intervals, Interval newInterval) {
        vector<Interval> res;
        int i = 0;
        
        while (i < intervals.size()) {
            if (newInterval.start <= intervals[i].end) break;
            res.push_back(intervals[i++]);
        }
        
        res.push_back(newInterval);
        while (i < intervals.size()) {
            if (res.back().end < intervals[i].start) break;
            
            res.back().start = min(res.back().start, intervals[i].start);
            res.back().end = max(res.back().end, intervals[i].end);
            ++i;
        }
        
        while (i < intervals.size()) res.push_back(intervals[i++]);
        
        return res;
    }
};