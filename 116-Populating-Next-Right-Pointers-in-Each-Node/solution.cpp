/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */
class Solution {
public:
    void connect(TreeLinkNode *root) {
        if(root == NULL) return;
        
        queue<TreeLinkNode*> q;
        TreeLinkNode** nxt = &root;
        
        q.push(root);
        q.push(NULL);
        TreeLinkNode* tmp;
        
        while(!q.empty())
        {
            root = q.front();
            q.pop();
            
            *nxt = root;
            
            if(root == NULL)
            {
                q.push(NULL);
                nxt = &tmp;
                if(q.size() <= 1) break;
                continue;
            }
            
            nxt = &root->next;
            
            if(root->left != NULL)
                q.push(root->left);
            if(root->right != NULL)
                q.push(root->right);
            
        }
    }
};