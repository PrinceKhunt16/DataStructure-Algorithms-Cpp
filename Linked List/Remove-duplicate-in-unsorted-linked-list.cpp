#include <bits/stdc++.h>
using namespace std;

class Node{
public:
    int data;
    Node *next;
};

void addNode(Node **head, int nodeValue){
    Node *newNode = new Node();
    newNode->data = nodeValue;
    newNode->next = (*head);
    (*head) = newNode;
}

Node* removeDuplicate(Node* head) {    
    // Make store to store unique element in map
    map<int, int> store;

    // Current element in assigned head
    Node* current = head;

    // Map in assigned first head
    store[current->data] = 1;
    
    // make previous and assiged current element 
    Node* previous = current;

    // Now current element jump to second element for previous element at head
    current = current->next;

    while (current != NULL){
        if(store[current->data]){
            previous->next = current->next;
            free(current);
        } else {
            store[current->data] = 1;
            previous = current;
        }
        current = previous->next;

    }

    return head;    
}

int main(){
    Node *head = NULL;
    addNode(&head, 7);
    addNode(&head, 4);
    addNode(&head, 2);
    addNode(&head, 5);
    addNode(&head, 8);
    addNode(&head, 3);
    addNode(&head, 7);
    addNode(&head, 4);
    addNode(&head, 6);
    addNode(&head, 3);
    addNode(&head, 1);
    addNode(&head, 3);

    removeDuplicate(head);

    while (head != NULL){
        cout << head->data << " ";
        head = head->next;
    }

    return 0;
}

// Input  : arr[] = { 7, 4, 2, 5, 8, 3, 7, 4, 6, 3, 1, 3 }
// Output : arr[] = { 3, 1, 6, 4, 7, 8, 5, 2 }

// Time Complexity : O(N)
// Space Complexity : O(N)

// GFG : https://practice.geeksforgeeks.org/problems/remove-duplicates-from-an-unsorted-linked-list/1