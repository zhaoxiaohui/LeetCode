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
    ListNode *deleteDuplicates(ListNode *head) {
		if(!head)return NULL;
		ListNode *retHead = NULL, *retTail = NULL, *it, *first;
		first = head;
		it = head->next;
		bool dup = false;
		while(it){
			if(first->val == it->val){			
				dup = true;
			}else{
				if(!dup){
					if(!retHead){
						retHead = retTail = first;
						retTail->next = NULL;
					}else{
						retTail->next = first;
						retTail = retTail->next;
						retTail->next = NULL;
					}
				}
				first = it;
				dup = false;
			}
			it = it->next;
		}
		if(!retHead && !dup){
			retHead = first;
			retHead->next = NULL;
		}else if(!dup && first){
			retTail->next = first;
			retTail = retTail->next;
			retTail->next = NULL;
		}
		return retHead;

    }
};