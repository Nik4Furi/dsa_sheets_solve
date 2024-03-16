
class cmp{
    public:
        bool operator()(ListNode* a,ListNode* b){
            return a->val > b->val;
        }
};

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int k = lists.size();

        if(k == 0) return NULL;

        priority_queue<ListNode*,vector<ListNode*>,cmp> pq;

        //insert first k nodes
        for(int i=0;i<k;i++){
            if(lists[i])
                pq.push(lists[i]);
        }

        ListNode* head=NULL,*tail = NULL;

        //Now traverse the heap
        while(!pq.empty()){
            ListNode* top = pq.top();
            pq.pop();

            if(top->next)
                pq.push(top->next);
            
            if(head == NULL){
                head = top;
                tail = top;
            }
            else {
                tail->next = top;
                tail = top;
            }
        }

        return head;
    }
};