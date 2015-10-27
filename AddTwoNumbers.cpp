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
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
        int up = 0, cur;
		if(!l1)return l2;
		if(!l2)return l1;
		ListNode *head = NULL, *tail = NULL;
		while(l1 && l2){
			cur = up + l1->val+l2->val;
			up = cur / 10;
			cur = cur % 10;
			if(!head){
				head = tail = new ListNode(cur);
			}else{
				tail->next = new ListNode(cur);
				tail = tail->next;
			}
			l1 = l1->next;
			l2 = l2->next;
		}
		while(l1){
			cur = up + l1->val;
			up = cur / 10;
			cur = cur % 10;
			if(!head){
				head = tail = new ListNode(cur);
			}else{
				tail->next = new ListNode(cur);
				tail = tail->next;
			}
			l1 = l1->next;
		}
		while(l2){
			cur = up + l2->val;
			up = cur / 10;
			cur = cur % 10;
			if(!head){
				head = tail = new ListNode(cur);
			}else{
				tail->next = new ListNode(cur);
				tail = tail->next;
			}
			l2 = l2->next;
		}
		if(up){
			tail->next = new ListNode(up);
			tail = tail->next;
		}
		return head;
    }
};
