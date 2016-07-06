/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
private:
    struct MergeList {
        ListNode *node;
        MergeList *next;
        MergeList(ListNode* n) : node(n), next(NULL) {}
    };
    MergeList* MList;
public:
    ListNode* sortList(ListNode* head) {
        if(head == NULL || head->next == NULL) return head;
        
        MList = new MergeList(head);
        MergeList *Mhead = MList;
        ListNode* tmp = head;
        ListNode* ttmp;
        
        //Build merge list
        while(tmp != NULL && tmp->next != NULL)
        {
            if(tmp->val > tmp->next->val)
                swap(tmp->val,tmp->next->val);
            ttmp = tmp->next;
            tmp = tmp->next->next;
            ttmp->next = NULL;
            if(tmp != NULL)
            {
                Mhead->next = new MergeList(tmp);
                Mhead = Mhead->next;
            }
        }
        
        //merge
        while(MList->next != NULL)
        {
            Mhead = MList;
            while(Mhead != NULL && Mhead->next != NULL)
            {
                //merge(Mhead, Mhead->next);
                ListNode **M1 = &(Mhead->node), *M2 = Mhead->next->node, *t1, *t2;
                while(*M1 != NULL && M2 != NULL)
                {
                    if((*M1)->val <= M2->val)
                    {
                        M1 = &((*M1)->next);
                    }
                    else
                    {
                        t1 = *M1;
                        t2 = M2->next;
                        *M1 = M2;
                        M2->next = t1;
                        M2 = t2;
                    }
                }
                if(*M1 == NULL)
                    *M1 = M2;
                
                Mhead->next = Mhead->next->next;
                Mhead = Mhead->next;
            }
        }
        
        return MList->node;
    }
};