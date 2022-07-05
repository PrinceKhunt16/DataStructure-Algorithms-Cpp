#include <iostream>
#include <cstdio>
using namespace std;

struct node{
    int data;
    struct node *next;

    node(int x){
        data = x;
        next = NULL;
    }
    
};

void push(struct node **head_ref, int new_data){
    struct node *new_node = new node(new_data);
    new_node->next = (*head_ref);
    (*head_ref) = new_node;

}

void printList(struct node *node){
    while (node != NULL){
        printf("%d ", node->data);
        node = node->next;
    }
    
    printf("\n");

}

void swapValue(node *first, node *second){
    int temp = first->data;
    first->data = second->data;
    second->data = temp;

}

node *partition(node *start, node *end){
    int pivotValue = start->data;
    node *i = start;
    node *j = start->next;

    while (j != end){
        if (j->data < pivotValue){
            i = i->next;
            swapValue(i, j);
        }

        j = j->next;

    }

    swapValue(i, start);

    return i;
}

void quickSortFunc(node *start, node *end){
    if (start != end){
        node *pivot = partition(start, end);
        quickSortFunc(start, pivot);
        quickSortFunc(pivot->next, end);
    }

}

void quickSort(struct node **headRef){
    quickSortFunc(*headRef, NULL);
    
}

int main(){
    int n, x;
    cin >> n;
    n = n - 1;
    cin >> x;
    
    node *temp, *head = new node(x);
    temp = head;

    while (n--){
        cin >> x;
        temp->next = new node(x);
        temp = temp->next;
    }

    quickSort(&head);

    printList(head);
    
    while (head != NULL){
        temp = head;
        head = head->next;
        free(temp);
    }

    return 0;
}


// INPUT  : arr[] = { 70, 99, 4, 88, 71, 8, 12, 70, 27 }
// OUTPUT : arr[] = { 4, 8, 12, 27, 70, 70, 71, 88, 99 }

// TIME COMPLEXITY : O(N)
// SPACE COMPLEXITY : O(1)

// LEETCODE : https://practice.geeksforgeeks.org/problems/quick-sort-on-linked-list/1#