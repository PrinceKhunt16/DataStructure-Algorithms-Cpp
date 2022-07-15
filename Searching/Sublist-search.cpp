#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node* next;
};

bool findList(Node* first, Node* second){
    Node* ptr1 = first, *ptr2 = second;
    
    if(first == NULL && second == NULL){
        return true;
    }

    if(first == NULL || (first != NULL && second == NULL)){
        return false;
    }

    while(second != NULL){
        ptr2 = second;

        while(ptr1 != NULL){
            if(ptr2 == NULL){
                return false;
            } 
            else if(ptr1 -> data == ptr2 -> data){
                ptr1 = ptr1 -> next;
                ptr2 = ptr2 -> next;
            }
            else {
                break;
            }
        }

        if(ptr1 == NULL){
            return true;
        }

        ptr1 = first;
        second = second -> next;
    }   

    return false;
}

Node *newNode(int key){
    Node *temp = new Node;
    temp -> data = key;
    temp -> next = NULL;
    return temp;
}

int main(){
    Node *a = newNode(1);
    a->next = newNode(2);
    a->next->next = newNode(3);
    a->next->next->next = newNode(4);
 
    Node *b = newNode(1);
    b->next = newNode(2);
    b->next->next = newNode(1);
    b->next->next->next = newNode(2);
    b->next->next->next->next = newNode(3);
    b->next->next->next->next->next = newNode(4);
 
    findList(a, b) ? cout << "1" : cout << "-1";
 
    return 0;
}

// Input  : arr = { 1, 2, 3, 4 }, arr2 = { 1, 2, 1, 2, 3, 4 }
// Output : 1

// Time Complexity : O(m * n)
// Space Complexity : O(1)

// GFG : https://www.geeksforgeeks.org/sublist-search-search-a-linked-list-in-another-list/