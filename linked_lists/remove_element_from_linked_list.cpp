#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode* RemoveElement(ListNode* head, int val) {
    if (head == nullptr) {
        return head;
    }

    ListNode* curr = head, *prev = nullptr;
    while (curr != nullptr) {
        if (curr->val == val) {
            if (prev == nullptr) head = curr->next;
            else prev->next = curr->next;
        } else
            prev = curr;
        curr = curr->next;
    }
    
    return head;
}