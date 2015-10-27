/**
 *	 Description: 
 *	      Author: zhaoxiaohui
 *	        Site: zhaoxiaohui.sinaapp.com
 *	        Date: 2014
 */

/**
 * Definition for singly-linked list with a random pointer.
 * struct RandomListNode {
 *     int label;
 *     RandomListNode *next, *random;
 *     RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
 * };
 */
class Solution {
public:
     RandomListNode *copyRandomList(RandomListNode *head) {
		RandomListNode *ret, *ret_tail, *it;
		it = head;
		unordered_map<RandomListNode *, RandomListNode *> nodes; 
		unordered_map<RandomListNode *, RandomListNode *>::iterator iit;
		while(it){
			if(it==head){
				ret = ret_tail = new RandomListNode(it->label);
				nodes[it] = ret;
			}else{
				iit = nodes.find(it);
				if(iit != nodes.end()){
					ret_tail->next = iit->second;
				}else{
					ret_tail->next = new RandomListNode(it->label);
					nodes[it] = ret_tail->next;
				}
				ret_tail = ret_tail->next;
			}
			iit = nodes.find(it->random);
			if(iit==nodes.end()){
				if(it->random != NULL)
					ret_tail->random = new RandomListNode(it->random->label);
				nodes[it->random] = ret_tail->random;
			}else{
				ret_tail->random = iit->second;
			}
			it = it->next;
		}
		return ret;
    }
};