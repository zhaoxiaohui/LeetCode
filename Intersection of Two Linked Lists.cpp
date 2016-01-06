/**
 *	 Description: https://leetcode.com/problems/intersection-of-two-linked-lists/
 *	      Author: zhaoxiaohui
 *	        Site: zhaoxiaohui.sinaapp.com
 *	        Date: 2015-1-6
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
	int getListLen(ListNode *head) {
		ListNode *iterator = head;
		int len = 0;
		while (iterator) {
			len++;
			iterator = iterator->next;
		}
		return len;
	}
	ListNode *goFrowardFirst(ListNode *head, int step) {
		ListNode *iterator = head;
		while (step--) {
			iterator = iterator->next;
		}
		return iterator;
	}
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int lena = 0, lenb = 0;
        lena = getListLen(headA);
        lenb = getListLen(headB);
        ListNode *one = lena > lenb ? goFrowardFirst(headA, lena - lenb) : goFrowardFirst(headB, lenb - lena);
        ListNode *two = lena > lenb ? headB : headA;
        while (one && two) {
        	if (one->val == two->val) {
        		return one;
        	}
        	one = one->next;
        	two = two->next;
        }
        return NULL;
    }
};