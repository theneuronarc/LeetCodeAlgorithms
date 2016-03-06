/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
typedef struct TreeNode TreeNode;

int findHeight(TreeNode* root){
        int height = 0;
        while(root){
            root = root->left;
            height++;
        }
        return height;
    }
    
    int countLeaves(TreeNode* root, int height){
        int count = 0;
        if(!root)
            return 0;
            
        if(height <= 1)
            return height;
        
        int rightHeight = findHeight(root->right) + 1;
        if(rightHeight < height){
            //Process Left Subtree
            count += countLeaves(root->left, height-1);
        }
        else{
            //Add leaves from Left Subtree
            count += (1 << (height-2));
            //Prcess right subtree
            count += countLeaves(root->right, height-1);
        }
        
        return count;
    }
    
    int countNodes(TreeNode* root) {
        if(!root)
            return 0;
        int height = findHeight(root);
        return countLeaves(root, height) + (1<<(height-1)) - 1;
    }
