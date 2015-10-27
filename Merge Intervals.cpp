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
int cmp(const Interval a1, const Interval a2){
	return a1.start < a2.start;
}
class Solution {
public:
    vector<Interval> merge(vector<Interval> &intervals) {
        sort(intervals.begin(), intervals.end(), cmp);
		vector<Interval> res;
		if(intervals.size() == 0)return res;
		res.push_back(intervals[0]);
		int num = 0;
		for(int i=1;i<intervals.size();i++){
			if(intervals[i].start <= res[num].end){
				res[num].end = max(intervals[i].end, res[num].end);
			}else{
				res.push_back(intervals[i]);
				num++;
			}
		}
		return res;
    }
};