/*
https://leetcode.com/problems/add-and-search-word-data-structure-design/
*/


#include "std_headers.h"

#if 0

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

bool searchRegExp(struct TrieNode* root, char* re) {
	if (!root)
		return false;

	TrieNode* node = root->head;
	bool res;
	while (node) {
		if (re[0] == '.' || node->c == re[0]) {
			if (re[0] == '\0') return true;
			res = searchRegExp(node, re + 1);
			if (res) return res;
			if (re[0] != '.') return res;
		}
		node = node->next;
	}

	return false;
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
#endif


struct TrieNode {
	char c;
	int isLeaf;
	int isWord;
	struct TrieNode* children[26];
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
bool searchX(struct TrieNode* root, char* word) {
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

	if (strlen(re) == 1) {
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

struct WordDictionary {
	struct TrieNode* root;
};

/** Initialize your data structure here. */
struct WordDictionary* wordDictionaryCreate() {
	struct WordDictionary* dict = (struct WordDictionary*)malloc(sizeof(struct WordDictionary));
	dict->root = trieCreate();
	return dict;
}

/** Inserts a word into the data structure. */
void addWord(struct WordDictionary* wordDictionary, char* word) {
	insert(wordDictionary->root, word);
}

/** Returns if the word is in the data structure. A word could
contain the dot character '.' to represent any one letter. */
bool search(struct WordDictionary* wordDictionary, char* word) {
	return searchRegExp(wordDictionary->root, word);
}

/** Deallocates memory previously allocated for the data structure. */
void wordDictionaryFree(struct WordDictionary* wordDictionary) {
	trieFree(wordDictionary->root);
	free(wordDictionary);
}

// Your WordDictionary object will be instantiated and called as such:
// struct WordDictionary* wordDictionary = wordDictionaryCreate();
// addWord(wordDictionary, "word");
// search(wordDictionary, "pattern");
// wordDictionaryFree(wordDictionary);