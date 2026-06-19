#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode* removeNthFromEnd(ListNode*& head, int n) {
    if (head == nullptr) return head;

    int count = 0;
    ListNode *temp = head;
    while (temp != nullptr) {
        count++;
        temp = temp->next;
    }

    int target_pos = (count - n) + 1;
    if (target_pos <= 1) {
        ListNode *temp_head = head;
        head = head->next;
        delete temp_head;
        return head;
    }

    ListNode *prev = head;
    for (int i = 1; prev != nullptr && i < (target_pos - 1); i++) {
        prev = prev->next;
    }

    if (prev == nullptr || prev->next == nullptr) return head;

    ListNode* node_to_delete = prev->next;
    prev->next = node_to_delete->next;
    delete node_to_delete;
    return head;
}
