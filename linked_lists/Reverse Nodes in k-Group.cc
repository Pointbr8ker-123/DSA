#include <bits/stdc++.h>
using namespace std;


// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};


class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        if (!head) return nullptr;

        ListNode* tail = head;
        for (int i = 0; i < k; i++) {
            if (!tail) return head;
            tail = tail->next;
        }

        ListNode newHead = reverseList(head, tail);
        head->next = reverseKGroup(tail, k);
        return newHead;
    }

private:
    ListNode* reverseList(ListNode* curr, ListNode* tail) {
        ListNode *next, *prev;
        prev = nullptr;

        while(curr != tail) {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
    }
};