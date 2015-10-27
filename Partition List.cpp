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
    ListNode *partition(ListNode *head, int x) {
        ListNode *it, *insert_it = NULL, *s, *pre = NULL, *ret = head;
		it = head;
		while(it && it->val < x){
			insert_it = it;
			it = it->next;
		}
		while(it){
			if(it->val < x){
				if(!insert_it){
					pre->next = it->next;
					it->next = head;
					insert_it = it;
					ret = it;
				}else{
					s = insert_it->next;
					insert_it->next = it;
					pre->next = it->next;
					it->next = s;

					insert_it = insert_it->next;
				}
			}
			pre = it;
			it = it->next;
		}
		return ret;
    }
};