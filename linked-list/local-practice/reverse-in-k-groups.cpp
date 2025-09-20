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

Node* reverseinK(Node* head, int k){
    if(head == NULL) return NULL;

    Node *prev = nullptr;
    Node *curr = head;
    Node *next = nullptr;
    int count = 0;

    while (curr != nullptr && count < k)
    {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        count++;
        curr = next;
    }

    if(next!=NULL){
        head->next = reverseinK(next, k);
    }   
    return prev;
}
bool isCircular(Node* head){
    bool fact = false;
    Node* temp = head->next;
    while(temp!=nullptr){
        if(temp == head){
            return true;
        }
        temp = temp->next;
    }
    return false;
}
bool floydsCircular(Node* head){
    Node* slow = head;
    Node* fast = head;
    while(fast!=nullptr && fast->next != nullptr){
        slow = slow -> next;
        fast = fast -> next -> next;
        if(slow == fast){
            return true;
        }
    }
    return false;
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
    Node* node6 = reverseinK(node1, 2);
    traverseList(node6);
    Node *node11 = new Node(1);
    Node *node12 = new Node(2);
    Node *node13 = new Node(3);
    Node *node14 = new Node(4);
    Node* node15 = new Node(16);
    node15->next = node11;
    node11->next = node12;
    node12->next = node13;
    node13->next = node14;
    node14->next = node15;
    cout << isCircular(node11);
    cout << floydsCircular(node11);
    cout << endl;
    return 0;
}