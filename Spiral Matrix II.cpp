/**
 *	 Description: 
 *	      Author: zhaoxiaohui
 *	        Site: zhaoxiaohui.sinaapp.com
 *	        Date: 2014
 */

class Solution {
public:
    vector<vector<int> > generateMatrix(int n)
    {
        int endWhile = n*n;
        vector<vector<int> > matrix(n, vector<int>(n));
        if(n==0)return matrix;
        int value=0, row=0, col=0, upbound = n-1, lowbound=0, total=1, s1=0, s2=1;
        matrix[0][0] = ++value;
        while((row+s1)<n && (col+s2)<n)
        {
            matrix[row+=s1][col+=s2] = ++value;
            if(value == endWhile)break;
            if(row == upbound && s1==1)
            {
                s1=0,s2=-1,total+=1;
            }
            else if(col == upbound && s2==1)
            {
                s1=1,s2=0,total+=1;
            }
            else if(col == lowbound && s2==-1)
            {
                s1=-1,s2=0, total+=1;
            }
            else if(row == lowbound && s1==-1)
            {
                s1=0,s2=1, total+=1;
            }
            if(total == 4)
            {
                total=0,upbound-=1, lowbound+=1;
            }
        }
        return matrix;
    }
};