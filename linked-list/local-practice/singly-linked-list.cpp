#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Node{
    public:
        int data;
        Node* next;
        Node(int data){
            this->data = data;
            this->next = NULL;
        }
};

void insertAtHead(Node* &head, int d){
    Node* temp = new Node(d);
    temp -> next = head;
    head = temp;
}
void traverseList(Node* head){
    while(head->next!=nullptr){
        cout << head -> data << " -> ";
        head = head->next;
    }
    cout << head->data;
    cout << endl;
}
void insertAtTail(Node* &head, int d){
    Node* temp = new Node(d);
    Node* temp2 = head;
    while(temp2->next != nullptr){
        temp2 = temp2->next;
    }
    temp2->next = temp;
}
void insertAtPosition(Node* &head, int d, int position){
    int count = 1;
    Node* temp = head;
    Node* newNode = new Node(d);
    while(count < position - 1){
        temp = temp -> next;
        count++;
    }
    newNode->next = temp->next;
    temp->next = newNode;
}
void deleteNode(Node* &head, int position){
    int count = 1;
    Node* temp = head;
    while(count < position - 1){
        temp = temp -> next;
        count++;
    }
    Node* todelete = temp->next;
    temp->next = temp->next->next;
    delete todelete;
}
int main(){
    Node* node1 = new Node(5);
    insertAtHead(node1, 10);
    insertAtHead(node1, 13);
    insertAtHead(node1, 14);
    traverseList(node1);
    insertAtTail(node1, 69);
    insertAtTail(node1, 69);
    insertAtPosition(node1, 2, 2);
    insertAtTail(node1, 69);
    traverseList(node1);
    deleteNode(node1, 3);
    traverseList(node1);
    cout << endl;
    return 0;
}