/*
https://leetcode.com/problems/word-search-ii/
*/

#include "std_headers.h"

struct TrieNode {
	char c;
	int isLeaf;
	int isWord;
	TrieNode* children[26];
};

typedef struct TrieNode TrieNode;

/** Initialize your data structure here. */
struct TrieNode* trieCreate() {
	TrieNode* root = (TrieNode*)malloc(sizeof(TrieNode));
	root->c = '\0';
	for (int i = 0; i < 26; i++)
		root->children[i] = 0;
	root->isLeaf = 1;
	root->isWord = 0;
	return root;
}

TrieNode* insertSub(TrieNode* target, char c) {
	if (!target)
		return 0;
	TrieNode* node;

	if (!target->children[c - 'a']) {
		node = (TrieNode*)malloc(sizeof(struct TrieNode));
		node->c = c;
		node->isLeaf = 1;
		for (int i = 0; i < 26; i++)
			node->children[i] = 0;
		target->children[c - 'a'] = node;
		target->isLeaf = 0;
	}
	else {
		node = target->children[c - 'a'];
	}

	return node;
}

/** Inserts a word into the trie. */
void insert(struct TrieNode* root, char* word) {
	TrieNode*node, *targetNode = root;
	for (int i = 0; i < strlen(word); i++) {
		targetNode = insertSub(targetNode, word[i]);
	}

	targetNode->isWord = 1;
}

TrieNode* find(TrieNode* root, char c) {
	if (!root)
		return root;
	return root->children[c - 'a'];	
}

/** Returns if the word is in the trie. */
bool search(struct TrieNode* root, char* word) {
	TrieNode* targetNode = root;
	for (int i = 0; i <= strlen(word); i++) {
		targetNode = targetNode->children[word[i] - 'a'];
		if (!targetNode)
			return false;
	}

	return (targetNode->isWord ? true : false);
}

int searchRegExp(struct TrieNode* root, char* re) {
	if (!root)
		return false;

	if (strlen(re) == 1){
		if (root->isWord && root->children[re[0] - 'a'])
			return true;
		else
			return false;
	}

	if (re[0] == '.') {
		for (int i = 0; i < 26; i++) {
			if (searchRegExp(root->children[i], re + 1))
				return true;
		}
	}
	else {
		if (root->children[re[0] - 'a']) {
			if (searchRegExp(root->children[re[0] - 'a'], re + 1))
				return true;
			else
				return false;
		}
	}

	return false;
}

/** Returns if there is any word in the trie
that starts with the given prefix. */
int startsWith(struct TrieNode* root, char* word) {
	TrieNode* targetNode = root;
	for (int i = 0; i < strlen(word); i++) {
		targetNode = targetNode->children[word[i] - 'a'];
		if (!targetNode)
			return 0;
	}

	return (targetNode->isWord ? 2 : 1);
}

/** Deallocates memory previously allocated for the TrieNode. */
void trieFree(struct TrieNode* root) {
	if (!root)
		return;

	for (int i = 0; i < 26; i++) {
		trieFree(root->children[i - 'a']);
	}
	free(root);
}


char** findWords(char** board, int boardRowSize, int boardColSize, char** words, int wordsSize, int* returnSize) {

}