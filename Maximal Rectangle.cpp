/**
 *	 Description: 
 *	      Author: zhaoxiaohui
 *	        Site: zhaoxiaohui.sinaapp.com
 *	        Date: 2014
 */

class Solution {
public:
    int maximalRectangle(vector<vector<char> > &matrix) {
		int rows = matrix.size();
		if(rows == 0)return 0;
		int cols = matrix[0].size();
		if(cols == 0)return 0;
		vector<int> height(cols, 0);
		int ret = 0;
		for(int i=0;i<rows;i++){
			for(int j=0;j<cols;j++){
				if(matrix[i][j] == '0'){
					height[j]=0;
					continue;
				}
				height[j]++;
			}
			ret = max(ret, largestRectangleArea(height));
		}
		return ret;
	}
	int largestRectangleArea(vector<int> &height) {
		int len = height.size();
		if(len == 0)return 0;
		stack<int> heights;
		heights.push(0);
		int ret = 0, curInd, curLlen, curRlen;
		for(int i=1;i<len;i++){
			if(heights.empty() || height[i] >= height[heights.top()]){
				heights.push(i);
			}else{
				curRlen = 0;
				while(!heights.empty() && height[i]<height[heights.top()]){
					curInd = heights.top();
					heights.pop();
					curLlen = heights.empty()?curInd:curInd-heights.top()-1;
					ret = max(ret, (curLlen+curRlen+1)*height[curInd]);
					curRlen  += curLlen+1;
				}
				heights.push(i);
			}
		}
		curRlen = 0;
		while(!heights.empty()){
			curInd = heights.top();
			heights.pop();
			curLlen = heights.empty()?curInd:curInd-heights.top()-1;
			ret = max(ret, (curLlen+curRlen+1)*height[curInd]);
			curRlen  += curLlen+1;
		}
		return ret;
	}
};