#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
};

void traverseList(Node *head)
{
    while (head->next != nullptr)
    {
        cout << head->data << " -> ";
        head = head->next;
    }
    cout << head->data;
    cout << endl;
}

void reverseList(Node *&head)
{
    Node *prev = nullptr;
    Node *curr = head;
    Node *next = nullptr;

    while (curr != nullptr)
    {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }

    head = prev;
}
void findMid(Node* head) {
    if (head == nullptr) {
        cout << "List is empty" << endl;
        return;
    }

    Node* slow = head;
    Node* fast = head;

    while (fast != nullptr && fast->next != nullptr) {
        slow = slow->next;        
        fast = fast->next->next;  
    }

    cout << "Middle: " << slow->data << endl;
}   

int main()
{
    Node *node1 = new Node(1);
    Node *node2 = new Node(2);
    Node *node3 = new Node(3);
    Node *node4 = new Node(4);
    // Node *node5 = new Node(5);
    node1->next = node2;
    node2->next = node3;
    node3->next = node4;
    // node4->next = node5;
    traverseList(node1);
    reverseList(node1);
    traverseList(node1);
    findMid(node1);
    cout << endl;
    return 0;
}