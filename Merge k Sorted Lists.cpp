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
     ListNode *mergeKLists(vector<ListNode *> &lists) {
        int len = lists.size();
		if(len == 0)return NULL;
		if(len == 1)return lists[0];
		int logt = (int)(log(len)/log(2));
		logt = logt < 1.0*log(len)/log(2) ? logt+1:logt;
		int pair;
		for(int i=1;i<=logt;i++){
			for(int j=0;j<len;j+=pow(2,i)){
				pair = j + pow(2,i-1);
				lists[j] = mergeTwo(lists[j], pair>=len?NULL:lists[pair]);
			}
		}
		return lists[0];
    }

	ListNode *mergeTwo(ListNode *one, ListNode *two){
		ListNode *head = NULL, *tail = NULL;
		while(one && two){
			if(one->val < two->val){
				if(!head){
					head = tail = one;
				}else{
					tail->next = one;
					tail = tail->next;
				}
				one = one->next;
				tail->next = NULL;
			}else{
				if(!head){
					head = tail = two;
				}else{
					tail->next = two;
					tail = tail->next;
				}
				two = two->next;
				tail->next = NULL;
			}
		}
		ListNode *t = one==NULL?two:one;
		while(t){
			if(!head){
				head = tail = t;
			}else{
				tail->next = t;
				tail = tail->next;
			}
			t = t->next;
			tail->next = NULL;
		}
		return head;
	}
};
