/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode *d = new ListNode();
        d->next=head;
        ListNode *f = d;
        ListNode *s = d;
        for(int i=1;i<=n;++i)
        {
            f=f->next;
        }
        
       
       
        while(f->next!=NULL)
        {
                f=f->next;
                s=s->next;
        }
       
           s->next = s->next->next;
                return d->next;
    }
         
            
    
};