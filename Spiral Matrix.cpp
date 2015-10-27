/**
 *	 Description: 
 *	      Author: zhaoxiaohui
 *	        Site: zhaoxiaohui.sinaapp.com
 *	        Date: 2014
 */

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int> > &matrix) {
		vector<int> ret;
		if(matrix.size()==0 || matrix[0].size() == 0)return ret;
		int indx=0, indy=0, dirx=0, diry=1, tx, ty;
		int stx = 0, lenx = matrix.size(), sty =0, leny = matrix[0].size();
		
		while(stx <lenx && sty < leny){
			ret.push_back(matrix[indx][indy]);
			tx = indx + dirx;
			ty = indy + diry;
			if(tx == lenx && dirx == 1){
				dirx = 0;
				diry = -1;
				leny--;
			}else if(ty == leny && diry == 1){
				dirx = 1;
				diry = 0;
				stx++;
			}else if(tx == stx-1 && dirx == -1){
				dirx = 0;
				diry = 1;
				sty++;
			}else if(ty ==sty-1 && diry == -1){
				dirx = -1;
				diry = 0;
				lenx--;
			}
			indx += dirx;
			indy += diry;
		}
		return ret;
	}
};