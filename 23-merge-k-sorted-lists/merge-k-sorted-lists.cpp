struct cmp{
    bool operator()(ListNode* a, ListNode* b){
        return a->val > b->val;
    }
};

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {

        priority_queue<ListNode*, vector<ListNode*>, cmp> pq;

        for(int i=0;i<lists.size();i++){
            if(lists[i])
                pq.push(lists[i]);
        }

        ListNode* res = nullptr;
        ListNode* tail = nullptr;

        while(!pq.empty()){

            ListNode* p = pq.top();
            pq.pop();

            if(res == nullptr){
                res = p;
                tail = p;
            }
            else{
                tail->next = p;
                tail = p;
            }

            if(p->next)
                pq.push(p->next);
        }

        if(tail)
            tail->next = nullptr;

        return res;
    }
};