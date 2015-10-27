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
     ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
        ListNode *head, *tail;
		head = tail = NULL;
		while(l1 && l2){
			if(l1->val < l2->val){
				if(!head){
					head = tail = l1;
					l1 = l1->next;
					tail->next = NULL;
				}else{
					tail->next = l1;
					tail = l1;
					l1 = l1->next;
					tail->next = NULL;
				}
			}else{
				if(!head){
					head = tail = l2;
					l2 = l2->next;
					tail->next = NULL;
				}else{
					tail->next = l2;
					tail = l2;
					l2 = l2->next;
					tail->next = NULL;
				}
			}
		}
		while(l1){
			if(!head){
				head = tail = l1;
				l1 = l1->next;
				tail->next = NULL;
			}else{
				tail->next = l1;
				tail = l1;
				l1 = l1->next;
				tail->next = NULL;
			}
		}
		while(l2){
			if(!head){
				head = tail = l2;
				l2 = l2->next;
				tail->next = NULL;
			}else{
				tail->next = l2;
				tail = l2;
				l2 = l2->next;
				tail->next = NULL;
			}
		}
		return head;
    }
};
