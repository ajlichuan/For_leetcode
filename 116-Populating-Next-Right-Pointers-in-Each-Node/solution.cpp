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
        
        TreeLinkNode *p;
        
        while(root != NULL)
        {
            p = root;
            
            while(p->left != NULL)
            {
                p->left->next = p->right;
                if(p->next != NULL)
                    p->right->next = p->next->left;
                else
                    break;
                p = p->next;
            }
            root = root->left;
        }
    }
};