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
ListNode* reverseBetween(ListNode* head,int left,int right){
 
        ListNode *a=head,*b=head;
        ListNode *prevA=NULL;

        int pos=1;

        while(pos<left)
        {
            prevA=a;
            a=a->next;
            pos++;
        }

        b=a;

        while(pos<right)
        {
            b=b->next;
            pos++;
        }

        ListNode* after=b->next;
        b->next=NULL;

        ListNode* prev=NULL;
        ListNode* curr=a;

        while(curr)
        {
            ListNode* nxt=curr->next;
            curr->next=prev;
            prev=curr;
            curr=nxt;
        }

        if(prevA)
            prevA->next=prev;
        else
            head=prev;

        a->next=after;

        return head; ;
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        int i=0;
        int n=0;
        ListNode* temp=head;

        while(temp){
            n++;
            temp=temp->next;
        }
        if(head==NULL || head->next==NULL) return head;

        for(i=1;i<n;i=i+k){
            if(i+(k-1)>n) break;

           head = reverseBetween(head, i, i+k-1);
        }
        return head;
        
    }
};