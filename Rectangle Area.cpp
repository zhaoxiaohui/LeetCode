/**
 *	 Description: 
 *	      Author: zhaoxiaohui
 *	        Site: zhaoxiaohui.sinaapp.com
 *	        Date: 2014
 */

class Solution {
public:
    int getMiddleTwo(int e1, int e2, int e3, int e4, int *a, int *b) {
        vector<int> sort_a;
        sort_a.push_back(e1);
        sort_a.push_back(e2);
        sort_a.push_back(e3);
        sort_a.push_back(e4);
        sort(sort_a.begin(), sort_a.end());
        *a = sort_a[1];
        *b = sort_a[2];
    }
    int computeArea(int A, int B, int C, int D, int E, int F, int G, int H) {
        int total = (G - E) * (H - F) + (C - A) * (D - B);
        // no cross area
        if ( E >= C || G <= A || F >= D || H <= B) {
            return total;
        }
        if (A == B && B == C && C == D) {
            return (G - E) * (H - F);
        }
        if (E == F && F == G && G == H) {
            return (C - A) * (D - B);
        }
        // get middle x, x+1
        int x1, x2;
        getMiddleTwo(A, C, E, G, &x1, &x2);
        // get middle y, y+1
        int y1, y2;
        getMiddleTwo(B, D, F, H, &y1, &y2);
        
        return total - (x2 - x1) * (y2 - y1);
    }
};