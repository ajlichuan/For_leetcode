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
        
        queue<pair<TreeLinkNode*, int>> q;
        TreeLinkNode** nxt = &root;
        
        q.push(make_pair(root,0));
        
        int last_level = 0, level;
        pair<TreeLinkNode*, int> tmp;
        
        while(!q.empty())
        {
            tmp = q.front();
            q.pop();
            root = tmp.first;
            level = tmp.second;
            
            if(level > last_level)
            {
                *nxt = NULL;
                last_level = level;
            }
            else
                *nxt = root;
            
            nxt = &root->next;
            
            if(root->left != NULL)
                q.push(make_pair(root->left, level+1));
            if(root->right != NULL)
                q.push(make_pair(root->right, level+1));
        }
        
        *nxt = NULL;
    }
};