#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node(int data) : data(data), next(nullptr) {}
};

void traverseList(Node* head) {
    if (!head) { cout << "(empty)\n"; return; }
    Node* cur = head;
    while (cur) {
        cout << cur->data;
        cur = cur->next;
        if (cur) cout << " -> ";
    }
    cout << '\n';
}

// Reverse nodes in groups of k (your logic was fine; minor tidy-ups)
Node* reverseinK(Node* head, int k) {
    if (!head || k <= 1) return head;

    Node* prev = nullptr;
    Node* curr = head;
    Node* next = nullptr;
    int count = 0;

    while (curr && count < k) {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
        ++count;
    }
    // head now is the last node of the reversed block
    if (next) head->next = reverseinK(next, k);
    return prev; // new head of this block
}

// Safer Floyd cycle detection (use this instead of isCircular)
bool hasCycle(Node* head) {
    Node* slow = head;
    Node* fast = head;
    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast) return true;
    }
    return false;
}

// If you still want a simple “isCircular”, reuse Floyd:
bool isCircular(Node* head) {
    return hasCycle(head);
}

// Remove cycle using Floyd: find meeting, then loop start, then cut prev->next
void removeCycle(Node*& head) {
    if (!head) return;

    Node* slow = head;
    Node* fast = head;
    bool found = false;

    // 1) Detect
    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast) { found = true; break; }
    }
    if (!found) return; // no cycle

    // 2) Find start of loop
    slow = head;
    Node* prev = nullptr; // will track node just before `fast`
    while (slow != fast) {
        slow = slow->next;
        prev = fast;
        fast = fast->next;
    }
    // Now `fast` (== slow) is at the start of the loop.
    // 3) Cut the link that points back to loop start
    if (prev) {
        prev->next = nullptr;
    } else {
        // Special case: cycle is a self-loop at head
        Node* cur = fast;
        while (cur->next != fast) cur = cur->next;
        cur->next = nullptr;
    }
}

int main() {
    // Linear list
    Node* node1 = new Node(1);
    Node* node2 = new Node(2);
    Node* node3 = new Node(3);
    Node* node4 = new Node(4);

    node1->next = node2;
    node2->next = node3;
    node3->next = node4;

    traverseList(node1);
    Node* node6 = reverseinK(node1, 2);
    traverseList(node6);

    // List with a cycle: 100 -> 2 -> 3 -> 4 -> 16 -> (back to 3)
    Node* node11 = new Node(100);
    Node* node12 = new Node(2);
    Node* node13 = new Node(3);
    Node* node14 = new Node(4);
    Node* node15 = new Node(16);

    node11->next = node12;
    node12->next = node13;
    node13->next = node14;
    node14->next = node15;
    node15->next = node13; // create cycle

    cout << boolalpha << hasCycle(node11) << '\n'; // should be true
    removeCycle(node11);
    cout << boolalpha << hasCycle(node11) << '\n'; // should be false
    traverseList(node11);

    return 0;
}
