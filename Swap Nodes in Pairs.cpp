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
    ListNode *swapPairs(ListNode *head) {
		int t;
		ListNode *tail = head;
		while(tail && tail->next){
			t = tail->val;
			tail->val = tail->next->val;
			tail->next->val = t;
			tail = tail->next->next;
		}
		return head;
    }
