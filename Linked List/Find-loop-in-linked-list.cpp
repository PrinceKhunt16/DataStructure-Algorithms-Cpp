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

bool findLoop(Node *head){

    if (head == NULL || head->next == NULL){
        return false;
    }

    Node *fast = head;
    Node *slow = head;

    while (fast->next && fast->next->next){
        fast = fast->next->next;
        slow = slow->next;

        if (fast == slow){
            return true;
        }
    }

    return false;
}

int main(){
    Node *head = NULL;
    addNode(&head, 20);
    addNode(&head, 4);
    addNode(&head, 15);
    addNode(&head, 10);

    head->next->next->next->next = NULL; // No Loop found

    head->next->next->next->next = head; // Loop found

    if (findLoop(head))
        cout << "Loop found";
    else
        cout << "No Loop found";

    return 0;
}

// INPUT  : head->next->next->next->next = NULL;
// OUTPUT : No Loop found

// TIME COMPLEXITY : O(N)
// SPACE COMPLEXITY : O(1)

// LEETCODE : https://leetcode.com/problems/linked-list-cycle/