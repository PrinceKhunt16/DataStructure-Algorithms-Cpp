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
    Node* temp = head;
    if(!temp) return NULL;
    
    while(temp->next != NULL){
        if(temp->data == temp->next->data){
            temp->next = temp->next->next;
        } else {
            temp = temp->next;
        }
    }
    
    return head;
}
int main(){
    Node *head = NULL;
    addNode(&head, 8);
    addNode(&head, 7);
    addNode(&head, 7);
    addNode(&head, 6);
    addNode(&head, 5);
    addNode(&head, 4);
    addNode(&head, 4);
    addNode(&head, 3);
    addNode(&head, 3);
    addNode(&head, 3);
    addNode(&head, 2);
    addNode(&head, 1);

    removeDuplicate(head);

    while (head != NULL){
        cout << head->data << " ";
        head = head->next;
    }

    return 0;
}

// INPUT  : arr[] = { 1, 2, 3, 3, 3, 4, 4, 5, 6, 7, 7, 8 }
// OUTPUT : arr[] = { 1, 2, 3, 4, 5, 6, 7, 8 }

// TIME COMPLEXITY : O(N)
// SPACE COMPLEXITY : O(N)

// LEETCODE : https://leetcode.com/problems/remove-duplicates-from-sorted-list/