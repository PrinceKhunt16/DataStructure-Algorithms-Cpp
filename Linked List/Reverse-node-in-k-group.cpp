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

Node *reverseKGroupNode(Node *head, int k){
    
    if (head == NULL || k == 1){
        return head;
    }

    Node *dummy = new Node();
    dummy->next = head;

    Node *currentNode = dummy;
    Node *nextNode = dummy;
    Node *prevNode = dummy;
    int counter = 0;

    while (currentNode->next != NULL){
        currentNode = currentNode->next;        
        counter++;
    }

    while (counter >= k){
        currentNode = prevNode->next;
        nextNode = currentNode->next;

        for (int i = 1; i < k; i++){
            currentNode->next = nextNode->next;
            nextNode->next = prevNode->next;
            prevNode->next = nextNode;
            nextNode = currentNode->next;
        }

        prevNode = currentNode;
        counter -= k;

    }

    return dummy->next;
}

int main(){
    Node *head = NULL;
    addNode(&head, 11);
    addNode(&head, 10);
    addNode(&head, 9);
    addNode(&head, 8);
    addNode(&head, 7);
    addNode(&head, 6);
    addNode(&head, 5);
    addNode(&head, 4);
    addNode(&head, 3);
    addNode(&head, 2);
    addNode(&head, 1);

    head = reverseKGroupNode(head, 3);

    while (head != NULL){
        cout << head->data << " ";
        head = head->next;
    }

    return 0;
}

// Input  : arr[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11 } k = 3
// Output : arr[] = { 3, 2, 1, 6, 5, 4, 9, 8, 7, 10, 11 }

// Time Complexity : O(N)
// Space Complexity : O(1)

// LEETCODE : https://leetcode.com/problems/reverse-nodes-in-k-group/