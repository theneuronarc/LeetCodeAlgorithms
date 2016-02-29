bool DFS(int* graph, int vertexCount, int* color, int source, int* schedule, int* start) {
	for (int i = 0; i < vertexCount; i++) {
		int present = *(graph + vertexCount*source + i);
		if (present) {
			if (!color[i]) {
				color[i] = 1;
				if (DFS(graph, vertexCount, color, i, schedule, start))
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


bool isCycle(int* graph, int vertexCount, int* schedule) {
	int* color = (int*)calloc(vertexCount, sizeof(int));
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

int* findOrder(int numCourses, int** prerequisites, int prerequisitesRowSize, int prerequisitesColSize, int* returnSize) {
	int* graph = (int*)calloc(numCourses*numCourses, sizeof(int));
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

	if (res)
		*returnSize = numCourses;
	else {
		*returnSize = 0;
		free(schedule);
		schedule = 0;
	}

	return schedule;
}