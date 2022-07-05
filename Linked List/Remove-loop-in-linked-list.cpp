#include <bits/stdc++.h>
using namespace std;

class Node
{
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

void removeLoop(Node *head){
    Node *low = head;
    Node *high = head;

    while (low != NULL && high != NULL && high->next != NULL){
        low = low->next;
        high = high->next->next;

        if (low == high){
            break;
        }

    }

    if (low == head){
        while (high->next != low){
            high = high->next;
        }
        
        high->next = NULL;
    
    } else if (low == high){
        low = head;
        
        while (low->next != high->next){
            low = low->next;
            high = high->next;
        }
        
        high->next = NULL;
    
    }
}

int main()
{
    Node *head = NULL;
    addNode(&head, 50);
    addNode(&head, 20);
    addNode(&head, 15);
    addNode(&head, 4);
    addNode(&head, 10);

    head->next->next->next->next->next = head->next->next;

    if (findLoop(head)){
        cout << "Loop found" << endl;
    } else {
        cout << "No Loop found" << endl;
    }

    removeLoop(head);

    if (findLoop(head)){
        cout << "Loop found" << endl;
    } else {
        cout << "No Loop found" << endl;
    }

    return 0;
}

// TIME COMPLEXITY : O(N)
// SPACE COMPLEXITY : O(1)

// LEETCODE : https://leetcode.com/problems/linked-list-cycle/