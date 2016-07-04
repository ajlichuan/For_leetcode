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
        TreeLinkNode *p = root;
        TreeLinkNode **nxt;
        
        while(root != NULL)
        {
            p = root;
            root = NULL;
            while(p)
            {
                if(p->left != NULL)
                {
                    if(root != NULL)
                    {
                        *nxt = p->left;
                    }
                    else
                    {
                        root = p->left;
                    }
                    nxt = &p->left->next;
                }
                if(p->right != NULL)
                {
                    if(root != NULL)
                    {
                        *nxt = p->right;
                    }
                    else
                    {
                        root = p->right;
                    }
                    nxt = &p->right->next;
                }
                p = p->next;
            }
        }
    }
};