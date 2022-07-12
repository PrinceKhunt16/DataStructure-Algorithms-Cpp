#include <bits/stdc++.h>
using namespace std;

class Node {
public:
	int data;
	Node* next;
};

Node* getIntesectionNode(Node* head1, Node* head2){
	Node *a = head1, *b = head2;
        
    while(a != b){
        if(a == NULL){
            a = head2;
        } else {
            a = a->next;
        }
        
        if(b == NULL){
            b = head1;
        } else {
            b = b->next;
        }
    }
        
    return a;     
}

int main(){
	Node* newNode;

	Node* head1 = new Node();
	head1->data = 10;

	Node* head2 = new Node();
	head2->data = 3;

	newNode = new Node();
	newNode->data = 6;
	head2->next = newNode;

	newNode = new Node();
	newNode->data = 9;
	head2->next->next = newNode;

	newNode = new Node();
	newNode->data = 15;
	head1->next = newNode;
	head2->next->next->next = newNode;

	newNode = new Node();
	newNode->data = 30;
	head1->next->next = newNode;

	head1->next->next->next = NULL;

	Node* intersectionPoint = getIntesectionNode(head1, head2);

	if (!intersectionPoint)
		cout << "No" << endl;
	else
		cout << intersectionPoint->data << endl;
}


// Input  : head1 = 10 15 30, head2 = 3 6 9 15 30
// Output : 15

// Time Complexity : O(N)
// Space Complexity : O(1)

// LEETCODE : https://leetcode.com/problems/intersection-of-two-linked-lists/submissions/