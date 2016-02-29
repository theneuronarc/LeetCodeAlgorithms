#include <stdio.h>


void rotateArray(int startIdx, int k, int N, int* ip, int* op) {
	int* chain = (int*)malloc(sizeof(int)*N);
	int count = 0;

	int nextIdx = ip[startIdx];
	
	chain[count++] = ip[startIdx];

	while (nextIdx != startIdx) {
		chain[count++] = ip[nextIdx];
		nextIdx = ip[nextIdx];
	}


}

int main()
{
	int N, T;
	int* A = (int*)malloc(sizeof(int)*N);
	int* map = (int*)malloc(sizeof(int)*N);


	int* rotA = (int*)calloc(N, sizeof(int));
	int startIdx = 0;
	

	scanf("%d", &N);
	scanf("%d", &T);

	for (int i = 0; i < N; i++) {
		scanf("%d", (A + i));
	}

	for (int i = 0; i < N; i++) {
		scanf("%d", (map + i));
	}












	return 0;
}
