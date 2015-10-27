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
   ListNode *reverseBetween(ListNode *head, int m, int n) {
        if(m == n)return head;
		ListNode *rhead, *rtail, *pretail, *prehead, *t;
		pretail = NULL;
		prehead = rhead = rtail = head;
		int i = m;
		while(--i){
			pretail = rhead;
			rhead = rhead->next;
		}
		i = n-m;
		prehead = rtail = rhead;
		while(i--){
			rtail = rtail->next;
		}
		prehead = rtail->next;
		while(rhead != rtail){
			t = rhead->next;
			rhead->next = prehead;
			prehead = rhead;
			rhead = t;
		}
		rtail->next = prehead;
		if(pretail != NULL){
			pretail->next = rtail;
			return head;
		}else return rtail;
    }
};