/**
 *	 Description: 
 *	      Author: zhaoxiaohui
 *	        Site: zhaoxiaohui.sinaapp.com
 *	        Date: 2014
 */

/**
 * Definition for undirected graph.
 * struct UndirectedGraphNode {
 *     int label;
 *     vector<UndirectedGraphNode *> neighbors;
 *     UndirectedGraphNode(int x) : label(x) {};
 * };
 */
class Solution {
public:
     UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
        if(!node)return node;
		map<UndirectedGraphNode *, bool> visit;
		queue<UndirectedGraphNode *> nodes;
		unordered_map<int, UndirectedGraphNode *> curNodes;
		visit[node] = true;
		nodes.push(node);
		UndirectedGraphNode *curNode;
		UndirectedGraphNode *ret = NULL;
		while(!nodes.empty()){
			curNode = nodes.front();
			nodes.pop();
			copyNode(curNodes, curNode, ret);
			int l = curNode->neighbors.size();
			for(int i=0;i<l;i++){
				if(!visit[curNode->neighbors[i]]){
					nodes.push(curNode->neighbors[i]);
					visit[curNode->neighbors[i]] = true;
				}
			}
		}
		return ret;
    }
	void copyNode(unordered_map<int,UndirectedGraphNode *> &curNodes, UndirectedGraphNode *node, UndirectedGraphNode *&ret){
		UndirectedGraphNode *newNode;
		auto curNode = curNodes.find(node->label);
		if(curNode == curNodes.end()){
			newNode = new UndirectedGraphNode(node->label);
			curNodes[node->label] = newNode;
		}else newNode = curNode->second;
		if(!ret)ret = newNode;
		for(auto it=node->neighbors.begin();it!=node->neighbors.end();it++){
			auto iit = curNodes.find((*it)->label);
			if(iit == curNodes.end()){
				UndirectedGraphNode *t = new UndirectedGraphNode((*it)->label);
				curNodes[(*it)->label] = t;
				newNode->neighbors.push_back(t);
			}else{
				newNode->neighbors.push_back(iit->second);
			}
		}
	}
};