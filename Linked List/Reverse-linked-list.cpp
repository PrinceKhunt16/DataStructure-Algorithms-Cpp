#include <bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    struct Node *next;
};

Node *newNode(int key){
    Node *temp = new Node;
    temp->data = key;
    temp->next = NULL;
    return temp;
}

void reverseNode(Node *curr, Node *prev, Node **head);

void reverseLinkedList(Node **head){
    
    if (!head){
        return; 
    } 
    
    reverseNode(*head, NULL, head);

}

void reverseNode(Node *curr, Node *prev, Node **head){

    if (!curr->next){
        *head = curr;
        curr->next = prev;
        return;
    }

    Node *next = curr->next;
    curr->next = prev;
    reverseNode(next, curr, head);

}

int main(){
    Node *head = newNode(1);
    head->next = newNode(2);
    head->next->next = newNode(3);
    head->next->next->next = newNode(4);
    head->next->next->next->next = newNode(5);
    head->next->next->next->next->next = newNode(6);
    head->next->next->next->next->next->next = newNode(7);
    head->next->next->next->next->next->next->next = newNode(8);

    reverseLinkedList(&head);

    while (head != NULL){
        cout << head->data << " ";
        head = head->next;
    }

    return 0;
}

// INPUT  : arr[] = { 1, 2, 3, 4, 5, 6, 7, 8 }
// OUTPUT : arr[] = { 8, 7, 6, 5, 4, 3, 2, 1 }

// TIME COMPLEXITY : O(N)
// SPACE COMPLEXITY : O(1)

// LEETCODE : https://leetcode.com/problems/reverse-linked-list/