/*
https://leetcode.com/problems/course-schedule/
*/

bool DFS(char* graph, int vertexCount, char* color, int source, int* schedule, int* start) {
	for (int i = 0; i < vertexCount; i++) {
		int present = *(graph + vertexCount*source + i);
		if (present) {
			if (!color[i]) {
				color[i] = 1;
				if (DFS(graph, vertexCount, color, i,schedule, start))
					return true;
				schedule[(*start)++] = i;
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


bool isCycle(char* graph, int vertexCount, int* schedule) {
	char* color = (char*)calloc(vertexCount, sizeof(char));
	int start = 0;
	for (int i = 0; i < vertexCount; i++) {
		if (!color[i]) {
			color[i] = 1;
			if (DFS(graph, vertexCount, color, i, schedule, &start))
				return true;
			color[i] = 2;
			schedule[start++] = i;
		}
	}
	free(color);
	return false;
}



bool canFinish(int numCourses, int** prerequisites, int prerequisitesRowSize, int prerequisitesColSize) {
	char* graph = (int*)calloc(numCourses*numCourses, sizeof(char));
	int* schedule = (int*)malloc(sizeof(int)*numCourses);
	int a, b;
	int res;
	for (int i = 0; i < prerequisitesRowSize; i++) {
		a = prerequisites[i][0];
		b = prerequisites[i][1];
		*(graph + numCourses*a + b) = 1;
	}
	res = !isCycle(graph, numCourses, schedule);
	for (int i = 0; i < numCourses / 2; i++) {
		int tmp = schedule[i];
		schedule[i] = schedule[numCourses - i - 1];
		schedule[numCourses - i - 1] = tmp;
	}
	free(graph);
	return res;
}

int* findOrder(int numCourses, int** prerequisites, int prerequisitesRowSize, int prerequisitesColSize, int* returnSize) {
	char* graph = (int*)calloc(numCourses*numCourses, sizeof(char));
	int* schedule = (int*)malloc(sizeof(int)*numCourses);
	int a, b;
	int res;
	for (int i = 0; i < prerequisitesRowSize; i++) {
		a = prerequisites[i][0];
		b = prerequisites[i][1];
		*(graph + numCourses*a + b) = 1;
	}
	res = !isCycle(graph, numCourses, schedule);
	for (int i = 0; i < numCourses / 2; i++) {
		int tmp = schedule[i];
		schedule[i] = schedule[numCourses - i - 1];
		schedule[numCourses - i - 1] = tmp;
	}

	free(graph);

	if (res) {
		*returnSize = numCourses;
	}
	else
		*returnSize = 0;
	return schedule;
}