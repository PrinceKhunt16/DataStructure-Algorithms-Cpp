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

void moveLastToFirst(Node** head) {  
    // If Linked List are empty so we dont move ahead and simple return form here.
    if(*head == NULL || (*head)->next == NULL){
        return;
    }

    // Here secondLast and last variable are temprary. This variable are not of Node Linked List.
    Node* secondLast;
    Node* last;

    // Point secondLast to Node Linked List's second last element and as well last to Node Linked List's last Node.
    while (last->next != NULL){
        secondLast = last;
        last = last->next;
    }
    
    // secondLast's next is NULL.
    secondLast->next = NULL;

    // last point to head.
    last->next = *head;

    // Now head have been last.
    *head = last;

}

int main(){
    Node *head = NULL;
    addNode(&head, 1);
    addNode(&head, 2);
    addNode(&head, 3);
    addNode(&head, 4);
    addNode(&head, 5);
    
    moveLastToFirst(&head);

    while (head != NULL){
        cout << head->data << " ";
        head = head->next;
    }

    return 0;
}

// Input  : arr[] = { 1, 2, 3, 4, 5 }
// Output : arr[] = { 5, 1, 2, 3, 4 }

// Time Complexity : O(N)
// Space Complexity : O(1)

// GFG : https://www.geeksforgeeks.org/move-last-element-to-front-of-a-given-linked-list/