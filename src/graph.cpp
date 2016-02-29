/*

*/
#include "std_headers.h"

struct Vertex;

typedef struct ListNodeX {
	struct Vertex* v;
	struct ListNodeX* next;
}ListNodeX;

typedef struct Vertex{
	int val;
	int color;
	int outDegree;
	ListNodeX* head;
}Vertex;

typedef struct {
	int vertexCount;	
	Vertex** vertexList;
}Graph;

Graph* createGraph(int numCourses, int** prerequisites, int prerequisitesRowSize, int prerequisitesColSize) {
	Graph* graph = (Graph*)malloc(sizeof(Graph));
	graph->vertexList = (Vertex**)malloc(numCourses*sizeof(Vertex*));
	graph->vertexCount = numCourses;
	for (int i = 0; i < numCourses; i++) {
		Vertex* v = (Vertex*)malloc(sizeof(Vertex));
		v->val = i;
		v->head = 0;
		v->color = 0;
		v->outDegree = 0;
		graph->vertexList[i] = v;
	}

	int a, b;
	
	for (int i = 0; i < prerequisitesRowSize; i++) {
		a = prerequisites[i][0];
		b = prerequisites[i][1];
		ListNodeX* n = (ListNodeX*)malloc(sizeof(ListNodeX));
		n->v = graph->vertexList[b];		
		n->next = graph->vertexList[a]->head;
		graph->vertexList[a]->head = n;		
		graph->vertexList[a]->outDegree++;
	}

	return graph;
}

void destroyGraph(Graph* graph){
	for (int i = 0; i < graph->vertexCount; i++) {
		if (graph->vertexList[i]) {
			ListNodeX*tmp, *node = graph->vertexList[i]->head;
			while (node) {
				tmp = node;
				node = node->next;
				free(tmp);
			}
		}
	}

	for (int i = 0; i < graph->vertexCount; i++) {
		free(graph->vertexList[i]);
	}

	free(graph->vertexList);
	free(graph);
}

bool DFS(Graph* graph, int source, int* schedule, int* start) {
	Vertex* v = graph->vertexList[source];
	ListNodeX* node = v->head;
	while (node) {
		if (!node->v->color) {
			node->v->color = 1;
			if (DFS(graph, source, schedule, start))
				return true;
			node->v->color = 2;
			schedule[(*start)++] = node->v->val;
		}
		else {
			if (node->v->color == 1) {
				return true;
			}
		}
	}
	return false;
}

bool graphTraversal(Graph* graph, int* schedule) {
	int start = 0;
	for (int i = 0; i < graph->vertexCount; i++) {
		if (!graph->vertexList[i]->color) {
			graph->vertexList[i]->color = 1;
			if (DFS(graph, i, schedule, &start)) {
				return true;
			}
			graph->vertexList[i]->color = 2;
			schedule[start++] = i;
		}
	}

	for (int i = 0; i <  graph->vertexCount / 2; i++) {
		int tmp = schedule[i];
		schedule[i] = schedule[graph->vertexCount - i - 1];
		schedule[graph->vertexCount - i - 1] = tmp;
	}

	return false;
}

int* findOrder(int numCourses, int** prerequisites, int prerequisitesRowSize, int prerequisitesColSize, int* returnSize) {
	int* schedule = (int*)malloc(sizeof(int)*numCourses);	
	Graph* graph = createGraph(numCourses, prerequisites, prerequisitesRowSize, prerequisitesColSize);
	bool isCycle = graphTraversal(graph, schedule);
	if (!isCycle) {
		*returnSize = graph->vertexCount;
	}
	else {
		*returnSize = 0;
		free(schedule);
		schedule = 0;
	}

	destroyGraph(graph);

	return schedule;
}






