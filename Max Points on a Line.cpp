/**
 *	 Description: 
 *	      Author: zhaoxiaohui
 *	        Site: zhaoxiaohui.sinaapp.com
 *	        Date: 2014
 */

/**
 * Definition for a point.
 * struct Point {
 *     int x;
 *     int y;
 *     Point() : x(0), y(0) {}
 *     Point(int a, int b) : x(a), y(b) {}
 * };
 */
class Solution {
public:
    int maxPoints(vector<Point> &points) {
		int numberOfPoints  = points.size();
		if(numberOfPoints == 0)return 0;
		int ret = 1, dup, vertical, curret;
		map<double, int> slopes;
		for(int i=0;i<numberOfPoints;i++){
			slopes.clear();
			dup = vertical = curret = 0;
			for(int j=i+1;j<numberOfPoints;j++){
				if(points[j].x == points[i].x && points[j].y == points[i].y){
					dup++;
				}else if(points[j].x == points[i].x){
					vertical++;
					if(curret < vertical)curret = vertical;
				}else{
					double slope = 1.0*(points[j].y-points[i].y)/(points[j].x-points[i].x);
					slopes[slope]++;
					if(curret < slopes[slope])curret = slopes[slope];
				}
			}
			if(ret < curret+dup+1){
				ret = curret+dup+1;
			}
		}
		return ret;
    }
};