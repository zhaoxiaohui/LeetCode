/**
 *	 Description: 
 *	      Author: zhaoxiaohui
 *	        Site: zhaoxiaohui.sinaapp.com
 *	        Date: 2014
 */

class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
		//bool ok = false;
		//isInterleaveUtil(s1, 0, s2, 0, s3, 0, ok);
		//return ok;
		return isInterleaveDP(s1, s2, s3);
	}

	void isInterleaveUtil(string s1, int id1, string s2, int id2, string s3, int id3, bool &ok){
		if(ok)return;
		if(id3 == s3.length()){
			ok = true;
			return;
		}
		if(id1 < s1.length() && s1[id1]==s3[id3]){
			isInterleaveUtil(s1, id1+1, s2, id2, s3, id3+1, ok);
		}
		if(ok)return;
		if(id2 < s2.length() && s2[id2]==s3[id3]){
			isInterleaveUtil(s1, id1, s2, id2+1, s3, id3+1, ok);
		}
	}

	bool isInterleaveDP(string s1, string s2, string s3){
		int len1 = s1.length(), len2 = s2.length(), len3 = s3.length();
		if(len1 + len2 != len3)return false;
		vector<vector<bool> > isInterL(len1+1, vector<bool>(len2+1, false));
		isInterL[0][0] = true;
		for(int i=1;i<=len1;i++){
			isInterL[i][0] = s3[i-1]==s1[i-1] && isInterL[i-1][0];
		}
		for(int j=1;j<=len2;j++){
			isInterL[0][j] = s3[j-1]==s2[j-1] && isInterL[0][j-1];
		}
		for(int i=1;i<=len1;i++){
			for(int j=1;j<=len2;j++){
				isInterL[i][j] = isInterL[i-1][j] && s3[i+j-1]==s1[i-1] ||
								isInterL[i][j-1] && s3[i+j-1]==s2[j-1];
			}
		}
		return isInterL[len1][len2];
	}
};