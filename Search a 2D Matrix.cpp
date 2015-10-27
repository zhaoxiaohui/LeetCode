/**
 *	 Description: 
 *	      Author: zhaoxiaohui
 *	        Site: zhaoxiaohui.sinaapp.com
 *	        Date: 2014
 */

class Solution {
public:
    bool searchMatrix(vector<vector<int> > &matrix, int target) {
        //first try to find the row using binary search
		int rows = matrix.size();
		if(rows == 0)return false;
		int cols = matrix[0].size();
		int toFindRowIndex = -1;
		int low = 0, high = rows-1, mid;
		while(low <= high){
			mid = (high-low)/2 + low;
			if(matrix[mid][0] == target)return true;
			if(matrix[mid][0] > target){
				toFindRowIndex = mid-1;
				high = mid - 1;
			}else{
				toFindRowIndex = mid;
				low = mid + 1;
			}
		}
		if(toFindRowIndex != -1){
			low = 0, high = cols-1;
			while(low <= high){
				mid = (high-low)/2 + low;
				if(matrix[toFindRowIndex][mid]==target)return true;
				if(matrix[toFindRowIndex][mid] > target){
					high = mid -1;
				}else{
					low = mid + 1;
				}
			}
		}
		return false;
    }
};