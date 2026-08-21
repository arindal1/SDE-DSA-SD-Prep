ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* temp = head;
        ListNode* prevNode = nullptr;

        while (temp != nullptr) {
            ListNode* KNode = findKNode(temp, k);
            if (KNode == nullptr) {
                if (prevNode != nullptr)
                    prevNode->next = temp;
                break;
            }

            ListNode* nextNode = KNode->next;
            KNode->next = nullptr;
            reverseList(temp);

            if (temp == head)
                head = KNode;
            else
                prevNode->next = KNode;
            
            prevNode = temp;
            temp = nextNode;
        }
        return head;
    }

    ListNode* findKNode(ListNode* head, int k) {
        k = k - 1;
        while (head != nullptr && k > 0) {
            head = head->next;
            k--;
        }
        return head;
    }

    ListNode* reverseList(ListNode* head) {
        if (head == nullptr)
            return head;
        
        ListNode* temp = head;
        ListNode* prev = nullptr;

        while (temp != nullptr) {
            ListNode* front = temp->next;
            temp->next = prev;
            prev = temp;
            temp = front;
        }
        return prev;
    }