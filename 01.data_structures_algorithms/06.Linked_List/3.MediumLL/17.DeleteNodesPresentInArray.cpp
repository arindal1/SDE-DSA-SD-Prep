ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        if (head == nullptr)
            return head;
        
        unordered_set<int> s(nums.begin(), nums.end());
        ListNode* temp = head;
        ListNode* back = nullptr;

        while (temp != nullptr) {
            ListNode* nextNode = temp->next;
            if (s.count(temp->val)) {
                if (back)
                    back->next = nextNode;
                else
                    head = nextNode;
            } else {
                back = temp;
            }
            temp = nextNode;
        }
        return head;
    }
