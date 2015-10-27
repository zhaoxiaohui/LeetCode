/**
 *	 Description: 
 *	      Author: zhaoxiaohui
 *	        Site: zhaoxiaohui.sinaapp.com
 *	        Date: 2014
 */

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *rotateRight(ListNode *head, int k) {
        if(!k)return head;
        ListNode *ret = head, *second = head, *fpre = NULL, *spre = NULL;
		int tk = k;
		while(tk && second){
			second = second->next;
			tk--;
			if(tk!=0 && second == NULL)second = head;
		}
		if(tk==0 && second == NULL)return head;
		while(ret && second){
			fpre = ret;
			ret = ret->next;
			spre = second;
			second = second->next;
		}
		if(fpre)fpre->next = NULL;
		if(spre)spre->next = head;
		return ret;

    }
};