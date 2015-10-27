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
    ListNode *removeNthFromEnd(ListNode *head, int n) {
        ListNode *ahead, *after, *pre;
		if(!head) return head;
		ahead = head;
		int k = n;
		while(--k && ahead){
			ahead = ahead->next;
		}
		if(!ahead)return head;
		after = head;
		while(ahead->next){
			ahead = ahead->next;
			pre = after;
			after = after->next;
		}
		if(after == head){
			pre = head;
			head = head->next;
			delete pre;
			pre = NULL;
			return head;
		}else{
			pre->next = after->next;
			delete after;
			after = NULL;
			return head;
		}
    }
};
