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
   bool hasCycle(ListNode *head) {
        if(head && head->next)
		{
			ListNode *slow, *fast;
			slow = head;
			fast = head->next->next;
			while(slow && fast){
				if(head == fast)return true;
				head = head->next;
				if(fast->next)
					fast = fast->next->next;
				else return false;
			}
			return false;
		}
		return false;
    }
};