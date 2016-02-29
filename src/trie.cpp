/*
https://leetcode.com/problems/implement-trie-prefix-tree/
*/

#include "std_headers.h"

struct TrieNode {
	char c;
	struct TrieNode* next;
	struct TrieNode* head;
};

typedef struct TrieNode TrieNode;

/** Initialize your data structure here. */
struct TrieNode* trieCreate() {
	TrieNode* root = (TrieNode*)malloc(sizeof(TrieNode));
	root->c = '\0';
	root->head = 0;
	root->next = 0;
	return root;
}

TrieNode* insertSub(TrieNode* target, char c) {
	if (!target)
		return 0;

	TrieNode* node = target->head;

	while (node) {
		if (node->c == c)
			return node;

		node = node->next;
	}

	node = (TrieNode*)malloc(sizeof(TrieNode));
	node->c = c;
	node->next = target->head;
	node->head = 0;
	target->head = node;

	return node;
}

/** Inserts a word into the trie. */
void insert(struct TrieNode* root, char* word) {
	TrieNode*node, *targetNode = root;
	for (int i = 0; i <= strlen(word); i++) {
		targetNode = insertSub(targetNode, word[i]);
	}
}

TrieNode* find(TrieNode* root, char c) {
	if (!root)
		return root;

	TrieNode* node = root->head;
	while (node) {
		if (node->c == c)
			return node;
		node = node->next;
	}

	return node;
}

/** Returns if the word is in the trie. */
bool search(struct TrieNode* root, char* word) {
	TrieNode* targetNode = root;
	for (int i = 0; i <= strlen(word); i++) {
		targetNode = find(targetNode, word[i]);
		if (!targetNode)
			return false;
	}

	return (!targetNode->head ? true : false);
}

/** Returns if there is any word in the trie
that starts with the given prefix. */
bool startsWith(struct TrieNode* root, char* prefix) {
	TrieNode* targetNode = root;
	for (int i = 0; i < strlen(prefix); i++) {
		targetNode = find(targetNode, prefix[i]);
		if (!targetNode)
			return false;
	}

	return true;
}

/** Deallocates memory previously allocated for the TrieNode. */
void trieFree(struct TrieNode* root) {
	TrieNode* node = root->head;
	TrieNode* tmp;
	if (!node) {
		free(root);
		return;
	}

	while (node) {
		tmp = node;
		node = node->next;
		trieFree(tmp);		
	}

	free(root);
}

// Your Trie object will be instantiated and called as such:
// struct TrieNode* node = trieCreate();
// insert(node, "somestring");
// search(node, "key");
// trieFree(node);

void trueMain() {
	TrieNode* root = trieCreate();

	insert(root,"abc");
	cout << search(root, "abc");
	cout << search(root,"ab");
	insert(root, "ab");
	cout << search(root, "ab");
	insert(root, "ab");
	cout << search(root, "ab");
	trieFree(root);
}