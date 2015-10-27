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
    void reorderList(ListNode *head) {
        vector<ListNode *> nodes;
		ListNode *it = head;
		while(it){
			nodes.push_back(it);
			it = it->next;
		}
		int len = nodes.size();
		for(int i=0,j=len-1;i<j-1;i++,j--){
			it = nodes[i]->next;
			nodes[i]->next = nodes[j];
			nodes[j]->next = it;
			nodes[j-1]->next = NULL;
		}
    }
};