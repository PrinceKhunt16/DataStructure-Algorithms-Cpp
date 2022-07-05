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

Node* findStartingPoint(Node *head){
    Node* low = head;
    Node* high = head;
   
    while (low != NULL && high != NULL && high->next != NULL){
        low = low->next;
        high = high->next->next;

        if (low == high){
            break;
        }

    }
    
    if(low != high){
        return NULL;
    }

    low = head;

    while (low != high){
        low = low->next;
        high = high->next;
    }

    return low;
}

int main(){
    Node *head = NULL;
    addNode(&head, 20);
    addNode(&head, 4);
    addNode(&head, 15);
    addNode(&head, 10);

    head->next->next->next->next = head->next; 

    Node* result = findStartingPoint(head);

    if (result == NULL)
        cout << "No Loop";
    else
        cout << "Loop starting node is " << result->data;

    return 0;
}

// TIME COMPLEXITY : O(N)
// SPACE COMPLEXITY : O(1)

// GFG : https://www.geeksforgeeks.org/find-first-node-of-loop-in-a-linked-list/