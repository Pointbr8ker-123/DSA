#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;

    Node(int val) {
        this->data = val;
    }
};

Node* SortLinkedList(Node*& head) {
    if (head == nullptr || head->next == nullptr) {
        return head;
    }

    Node* dummy = new Node(0);
    dummy->next = head;

    Node* prev = head;
    Node* current = head->next;

    while(current != nullptr) {
        if (current->data >= prev->data) {
            prev = current;
            current = current->next;
        } else {
            Node* temp = dummy;

            while (temp->next->data < current->data) {
                temp = temp->next;
            }
            prev->next = current->next;
            current->next = temp->next;
            temp->next = current;
            current = prev->next;
        }
    }
    Node* new_head = dummy->next;
    delete dummy;
    return new_head;
}

void PrintLinkedList(Node* node) {
    cout << "[ ";
    while (node != nullptr) {
        cout << node->data << " ";
        node = node->next;
    }
    cout << "]" << endl;
}

int main() {
    Node* head = new Node(10);
    Node* second = new Node(50);
    Node* third = new Node(30);

    head->next = second;
    second->next = third;
    third->next = nullptr;

    PrintLinkedList(head);

    Node* new_head = SortLinkedList(head);

    PrintLinkedList(new_head);
    return 0;
}