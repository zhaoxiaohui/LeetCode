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
        if(!head || !head->next)return head;
		ListNode *pre, *it, *delStart, *delEnd, *del;
		pre = head;
		it = head->next;
		delEnd = NULL;
		while(it){
			if(it->val == pre->val){
				delEnd = it;
			}else{
				delStart = pre->next;
				while(delEnd && delStart!=delEnd->next){
					del = delStart->next;
					delete delStart;
					delStart  = NULL;
					delStart = del;
				}
				delEnd = NULL;
				pre->next = it;
				pre = it;
			}
			it = it->next;
		}
		if(delEnd){
		    delStart = pre->next;
			while(delStart!=delEnd->next){
				del = delStart->next;
				delete delStart;
				delStart  = NULL;
				delStart = del;
			}
			delEnd = NULL;
			pre->next = NULL;
		}
		return head;
    }
};