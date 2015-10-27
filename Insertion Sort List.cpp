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
     ListNode *insertionSortList(ListNode *head) {
        ListNode *rethead = NULL, *reth, *pre, *next;
		while(head){
			if(rethead == NULL){
				rethead = head;
					head = head->next;
				rethead->next = NULL;
			
			}else{
				reth = rethead;
				pre = NULL;
				while(reth && head->val > reth->val){
					pre = reth;
					reth = reth->next;
				}
				if(pre){
					next = pre->next;
					pre->next = head;
					reth = head;
					head = head->next;
					reth->next = next;
				}else{
					reth = head;
					head = head->next;
					reth->next = rethead;
					rethead = reth;
				}
			}
		}
		return rethead;
    }
};