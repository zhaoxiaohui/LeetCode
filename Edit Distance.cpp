/**
 *	 Description: 
 *	      Author: zhaoxiaohui
 *	        Site: zhaoxiaohui.sinaapp.com
 *	        Date: 2014
 */

class Solution {
public:
    int minDistance(string word1, string word2) {
		int len1 = word1.length(), len2 = word2.length();
		if(len1 == 0)return len2;
		if(len2 == 0)return len1;
		vector<vector<int> > dist(len1+1, vector<int>(len2+1, 0));
		for(int j=0;j<=len2;j++){
			dist[0][j] = j;
		}
		for(int i=0;i<=len1;i++){
			dist[i][0] = i;
		}
		for(int i=1;i<=len1;i++){
			for(int j=1;j<=len2;j++){
				if(word1[i-1] == word2[j-1])dist[i][j] = dist[i-1][j-1];
				else dist[i][j] = min(dist[i-1][j], min(dist[i][j-1], dist[i-1][j-1]))+1;
			}
		}
		return dist[len1][len2];
    }
};