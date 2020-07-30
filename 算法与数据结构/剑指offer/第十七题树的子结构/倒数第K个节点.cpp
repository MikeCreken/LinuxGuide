//author xiaolan
class Solution {
public:
    ListNode* FindKthToTail(ListNode* pListHead, unsigned int k) {
        if(pListHead==NULL||k==0)
            return NULL;
        ListNode*p2=pListHead,*p1=pListHead;
        //先走k步
        for(int i=1;i<k;++i)
        {
            if(p1->next!=NULL)
                p1=p1->next;
            else
                return NULL;
        }
        //同时出发
        while(p1->next!=NULL)
        {
            p1=p1->next;
            p2=p2->next;
        }
        return p2;
    }
};