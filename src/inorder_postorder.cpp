#include "std_headers.h"

class Solution {
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int size = inorder.size();
        
        TreeNode** path = (TreeNode**)malloc(sizeof(TreeNode*)*(size + 1));
        TreeNode* dummy = new TreeNode(0xDEADBEEF);
        path[0] = dummy;
        TreeNode* root = dummy;
        
        int pathIdx = 0;
        int inIdx = size - 1;
        int postIdx = size - 1;
        
        while(postIdx >= 0){
            if(path[pathIdx]->val == inorder[inIdx]){
            	// Check Retreat
                root = path[pathIdx];
                pathIdx--;
                inIdx--;
            }
            else{
            	// Form right chain for left subtree.
                TreeNode* head= new TreeNode(0);
                TreeNode* node = head;
                
                while(postorder[postIdx] != inorder[inIdx]){
                    node->right = new TreeNode(postorder[postIdx]);
                    postIdx--;
                    node = node->right;
                    path[++pathIdx] = node;
                }
                
                node->right = new TreeNode(postorder[postIdx]);
                node = node->right;
                path[++pathIdx] = node;
                postIdx--;
                root->left = head->right;
                delete head;
            }
        }
        
        return dummy->left;
    }
};

int search(int* data, int size, int val) {
	for (int i = 0; i < size; i++) {
		if (data[i] == val)
			return i;
	}
	return -1;
}


struct TreeNode* buildTree(int* inorder, int inorderSize, int* postorder, int postorderSize) {
	if (!inorderSize)
		return NULL;
	int pIdx = postorderSize - 1;
	int partition;
	int leftCount, rightCount;
	TreeNode* top = (TreeNode*)malloc(sizeof(TreeNode));
	top->val = postorder[pIdx];
	top->right = NULL;
	top->left = NULL;

	partition = search(inorder, inorderSize, top->val);
	if (partition == -1)
		return top;

	leftCount = partition;
	rightCount = inorderSize - leftCount - 1;

	if (leftCount) {
		top->left = buildTree(inorder, leftCount, postorder, leftCount);
	}

	if (rightCount) {
		top->right = buildTree(inorder + leftCount + 1, rightCount, postorder + leftCount, rightCount);
	}

	return top;
}
