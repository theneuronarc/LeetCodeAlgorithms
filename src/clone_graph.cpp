/*
https://leetcode.com/problems/clone-graph/
*/

#include "std_headers.h"

typedef struct UndirectedGraphNode {
    int label;
    vector<UndirectedGraphNode *> neighbors;
    UndirectedGraphNode(int x) : label(x) {};
}UndirectedGraphNode;

class Solution {
public:
	UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
		std::queue<UndirectedGraphNode*> fifo;
		unordered_map<UndirectedGraphNode*, UndirectedGraphNode*> cloneMap;
		int size;
		UndirectedGraphNode* neighbor;
		UndirectedGraphNode* cloneNode, *cloneNeighbor, *source;

		if (!node)
			return NULL;

		fifo.push(node);
		source = new UndirectedGraphNode(node->label);
		cloneMap.insert(std::make_pair(node, source));
		
		while (!fifo.empty()) {			
			node = fifo.front();
			fifo.pop();
			size = node->neighbors.size();
			cloneNode = cloneMap[node];

			for (int i = 0; i < size; i++) {
				neighbor = node->neighbors[i];
				
				if (!cloneMap[neighbor]) {
					cloneNeighbor = new UndirectedGraphNode(neighbor->label);
					cloneMap[neighbor] = cloneNeighbor;
					fifo.push(neighbor);
				}
				else {
					cloneNeighbor = cloneMap[neighbor];
				}

				cloneNode->neighbors.push_back(cloneNeighbor);
			}
		}

		return source;
	}
};


class Solution1 {
public:
	UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
		std::queue<UndirectedGraphNode*> fifo;
		unordered_map<UndirectedGraphNode*, UndirectedGraphNode*> cloneMap;
		int size;
		UndirectedGraphNode* neighbor;
		UndirectedGraphNode* cloneNode, *cloneNeighbor, *source;

		if (!node)
			return NULL;

		fifo.push(node);
		source = new UndirectedGraphNode(node->label);
		cloneMap.insert(std::make_pair(node, source));

		while (!fifo.empty()) {
			node = fifo.front();
			fifo.pop();
			size = node->neighbors.size();
			cloneNode = cloneMap[node];

			for (int i = 0; i < size; i++) {
				neighbor = node->neighbors[i];

				if (!cloneMap[neighbor]) {
					cloneNeighbor = new UndirectedGraphNode(neighbor->label);
					cloneMap[neighbor] = cloneNeighbor;
					fifo.push(neighbor);
				}
				else {
					cloneNeighbor = cloneMap[neighbor];
				}

				cloneNode->neighbors.push_back(cloneNeighbor);
			}
		}

		return source;
	}
};

void cloneGraphMain() {
	Solution obj;
}