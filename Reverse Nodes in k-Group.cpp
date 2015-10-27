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
    ListNode *reverseKGroup(ListNode *head, int k) {
		int poind;
		ListNode *iterator = head, *pre = NULL, *curhead, *curtail;
		bool isFirstReverse = true;
		while(iterator){
			poind = 0;
			curhead = iterator;
			while(iterator && poind<k){
				curtail = iterator;
				iterator = iterator->next;
				poind++;
			}
			if(poind != k)break;
			reverseList(pre, curhead, curtail);
			if(isFirstReverse){
				head= curtail;
				isFirstReverse = false;
			}
			pre = curhead;
		}
		return head;
    }

	void reverseList(ListNode *pre, ListNode *head, ListNode *tail){
		ListNode *t, *sortedHead = tail->next;
		while(head != tail){
			t = head->next;
			head->next = sortedHead;
			sortedHead = head;
			head = t;
		}
		tail->next = sortedHead;
		if(pre)pre->next = tail;
	}
};
