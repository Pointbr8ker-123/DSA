// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
private:
    int count_list(ListNode* head) {
        int count = 0;
        ListNode* temp = head;
        while (temp) {
            count++;
            temp = temp->next;
        }
        return count;
    }

public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(head == nullptr) return head;

        int count = count_list(head);
        int target_pos = count - n + 1;

        if (target_pos <= 1) {
            ListNode* temp = head;
            head = head->next;
            delete temp;
            return head;
        }

        ListNode* prev = head;

        for (int i = 1; prev != nullptr && i < (target_pos - 1); i++) {
            prev = prev->next;
        }

        if (!prev || !prev->next) return head;

        ListNode* node_to_delete = prev->next;
        prev->next = node_to_delete->next;
        delete node_to_delete;
        return head;
    }
};