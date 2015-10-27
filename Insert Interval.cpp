/**
 *	 Description: 
 *	      Author: zhaoxiaohui
 *	        Site: zhaoxiaohui.sinaapp.com
 *	        Date: 2014
 */

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
   vector<Interval> insert(vector<Interval> &intervals, Interval newInterval) {
        vector<Interval> ret;
		if(intervals.size() == 0){
			ret.push_back(newInterval);
			return ret;
		}
		bool combine = false;
		auto pre = intervals.begin();
		auto next = pre + 1;
		if(newInterval.end < pre->start){
			ret.push_back(newInterval);
			combine = true;
		}else if(pre->end >= newInterval.start){
			pre->start = min(pre->start, newInterval.start);
			pre->end = max(pre->end, newInterval.end);
			combine = true;
		}
		while(next != intervals.end()){
			if(combine){
				if(pre->end >= next->start){
					pre->end = max(pre->end, next->end);
					next++;
				}else{
					ret.push_back(*pre);
					pre = next++;
				}
			}else{
				ret.push_back(*pre);
				pre = next++;
				if(newInterval.end < pre->start){
					ret.push_back(newInterval);
					combine = true;
				}else if(pre->end >= newInterval.start){
					pre->start = min(pre->start, newInterval.start);
					pre->end = max(pre->end, newInterval.end);
					combine = true;
				}
			}
		}
		ret.push_back(*pre);
		if(!combine)ret.push_back(newInterval);
		return ret;
    }
};