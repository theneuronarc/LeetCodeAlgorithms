/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class BSTIterator {
    stack<TreeNode*> stk;
    TreeNode* root;
    bool isReverse;
public:
    
    BSTIterator(TreeNode *root, bool direction = false) {
        this->root = root;
        isReverse = direction;
        TreeNode* cur = root;
        while(cur){
            stk.push(cur);
            if(!isReverse)
                cur = cur->left;
            else
                cur = cur->right;
        }
    }

    /** @return whether we have a next smallest number */
    bool hasNext() {
        return !stk.empty();
    }

    /** @return the next smallest number */
    int next() {
        if(stk.empty())
            return -1;
            
        TreeNode* cur = stk.top();
        int retVal = cur->val;
        stk.pop();
        if(isReverse)
            cur = cur->left;
        else
            cur = cur->right;
            
        while(cur){
            stk.push(cur);
            if(!isReverse)
                cur = cur->left;
            else
                cur = cur->right;
        }
        
        return retVal;
    }
};

/**
 * Your BSTIterator will be called like this:
 * BSTIterator i = BSTIterator(root);
 * while (i.hasNext()) cout << i.next();
 */
