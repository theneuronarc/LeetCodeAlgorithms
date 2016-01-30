/*
https://leetcode.com/problems/min-stack/
*/


typedef struct {
	int val;
	int minElement;
}Key;

typedef struct {
	int maxSize;
	int top;
	Key* data;
} MinStack;

#define maxSize stack->maxSize
#define top stack->top
#define minIdx stack->minIdx
#define data stack->data


void minStackCreate(MinStack *stack, int size) {
	maxSize = size;
	top = -1;
	data = (Key*)malloc(sizeof(Key)*size);
}

void minStackPush(MinStack *stack, int element) {
	if (top >= maxSize - 1) {
		return;
	}
	top++;
	data[top].val = element;
	data[top].minElement = element;

	if (top > 0 && data[top].minElement > data[top - 1].minElement) {
		data[top].minElement = data[top - 1].minElement;
	}
}

void minStackPop(MinStack *stack) {
	if (top >= 0) {
		top--;
	}

	return;
}

int minStackTop(MinStack *stack) {
	if (top >= 0) {
		return data[top].val;
	}

	return -1;
}

int minStackGetMin(MinStack *stack) {
	if (top >= 0) {
		return data[top].minElement;
	}

	return -1;
}

void minStackDestroy(MinStack *stack) {
	free(data);
}