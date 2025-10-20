class Solution {
public:
    struct Cmp {
        bool operator()(const ListNode* a, const ListNode* b) const {
            return a->val > b->val; // min-heap: top is smallest value
        }
    };

    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if (lists.empty()) return nullptr;
        priority_queue<ListNode*, vector<ListNode*>, Cmp> pq;
        for (ListNode* node : lists) {
            if (node) pq.push(node);
        }
        ListNode dummy(-1);
        ListNode* tail = &dummy;

        while (!pq.empty()) {
            ListNode* smallest = pq.top();
            pq.pop();
            tail->next = smallest;
            tail = tail->next;
            if (smallest->next) {
                pq.push(smallest->next);
            }
        }
        tail->next = nullptr;

        return dummy.next;
    }
};
