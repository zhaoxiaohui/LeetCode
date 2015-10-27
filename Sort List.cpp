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
    ListNode *sortList(ListNode *head) {
		ListNode *it;
		//calculate N
		int length = 0;
		for(it = head;it!=NULL;it = it->next){
			length++;
		}

		int halfStep, curStep;
		ListNode *preHead,*secondHead, *tempTail, *splitTail;
		//merge sort
		for(int step = 1;step<length;step = step*2){
			halfStep = step;
			it = head;
			while(it){
				curStep = 1;
				preHead = tempTail =it;
				while(curStep<=halfStep && it){
					tempTail = it;
					it = it->next;
					curStep++;
				}
				if(!it){
					if(splitTail)
						splitTail->next = preHead;
					break;
				}
				tempTail->next = NULL;
				curStep = 1;
				secondHead = tempTail =it;
				while(curStep<=halfStep && it){
					tempTail = it;
					it = it->next;
					curStep++;
				}
				tempTail->next = NULL;
				if(preHead == head)head = mergeSort(preHead, secondHead, splitTail);
				else{
					tempTail = splitTail;
					tempTail->next = mergeSort(preHead, secondHead, splitTail);
				}
			}
		}
		return head;
    }
	ListNode *mergeSort(ListNode *preHead, ListNode *secondHead, ListNode *&splitTail){
		if(secondHead == NULL)return preHead;
		ListNode *ret, *it = NULL, *preIt = preHead, *secondIt = secondHead;
		
		while(preIt && secondIt){
			if(preIt->val < secondIt->val){
				if(!it){
					ret = it = preIt;
				}else{
					it->next = preIt;
					it = it->next;
				}
				preIt = preIt->next;
				it->next = NULL;
			}else{
				if(!it){
					ret = it = secondIt;
				}else{
					it->next = secondIt;
					it = it->next;
				}
				secondIt = secondIt->next;
				it->next = NULL;
			}
		}
		while(preIt){
			if(!it){
				ret = it = preIt;
			}else{
				it->next = preIt;
				it = it->next;
			}
			preIt = preIt->next;
			it->next = NULL;
		}
		while(secondIt){
			if(!it){
				ret = it = secondIt;
			}else{
				it->next = secondIt;
				it = it->next;
			}
			secondIt = secondIt->next;
			it->next = NULL;
		}
		splitTail = it;
		return ret;
	}
};