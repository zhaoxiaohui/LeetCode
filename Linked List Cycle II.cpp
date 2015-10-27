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
    ListNode *detectCycle(ListNode *head) {
        if(!head)return head;
		ListNode *slow, *fast;
		slow = fast = head;
		while(slow && fast){
			slow = slow->next;
			fast = fast->next;
			if(!fast)return NULL;
			fast = fast->next;
			if(slow == fast)break;
		}
		if(!slow || !fast)return NULL;
		slow = head;
		while(slow != fast){
			slow = slow->next;
			fast = fast->next;
		}
		return slow;
    }
};