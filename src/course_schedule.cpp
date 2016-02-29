/*
https://leetcode.com/problems/course-schedule/
*/



bool DFS(char* graph, int vertexCount, char* color, int source) {
	for (int i = 0; i < vertexCount; i++) {
		int present = *(graph + vertexCount*source + i);
		if (present) {
			if (!color[i]) {
				color[i] = 1;
				if (DFS(graph, vertexCount, color, i))
					return true;
				color[i] = 2;
			}
			else {
				if (color[i] == 1)
					return true;
			}
		}
	}

	return false;
}


bool isCycle(char* graph, int vertexCount) {
	char* color = (char*)calloc(vertexCount, sizeof(char));

	for (int i = 0; i < vertexCount; i++) {
		if (!color[i]) {
			color[i] = 1;
			if (DFS(graph, vertexCount, color, i))
				return true;
			color[i] = 2;
		}
	}
	free(color);
	return false;
}



bool canFinish(int numCourses, int** prerequisites, int prerequisitesRowSize, int prerequisitesColSize) {
	char* graph = (int*)calloc(numCourses*numCourses, sizeof(char));
	int a, b;
	int res;
	for (int i = 0; i < prerequisitesRowSize; i++) {
		a = prerequisites[i][0];
		b = prerequisites[i][1];
		*(graph + numCourses*a + b) = 1;
	}
	res = !isCycle(graph, numCourses);
	free(graph);
	return res;
}