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
    ListNode* middleNode(ListNode* head) {
        int n = get_length(head);
        int size = n/2;

        ListNode* temp = head;
        while (temp != nullptr && size > 0) {
            temp = temp->next;
            size--;
        }
        head = temp;
        return head;
    }

private:
    int get_length(ListNode* head) {
        ListNode* temp = head;
        int count = 0;
        while (temp != nullptr) {
            count++;
            temp = temp->next;
        }
        return count;
    }
};