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
private:
    stack<TreeNode*> st;
    TreeNode* now;
    
public:
    BSTIterator(TreeNode *root) {
        now = root;
    }

    /** @return whether we have a next smallest number */
    bool hasNext() {
        return now != NULL || !st.empty();
    }

    /** @return the next smallest number */
    int next() {
        while(now != NULL)
        {
            st.push(now);
            now = now->left;
        }
        
        now = st.top();
        st.pop();
        
        int val = now->val;
        
        now = now->right;
        
        return val;
    }
};

/**
 * Your BSTIterator will be called like this:
 * BSTIterator i = BSTIterator(root);
 * while (i.hasNext()) cout << i.next();
 */