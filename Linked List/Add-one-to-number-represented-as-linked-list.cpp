#include <bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    struct Node *next;

    Node(int x){
        data = x;
        next = NULL;
    }
};

void printList(Node *node){
    while (node != NULL){
        cout << node->data;
        node = node->next;
    }
    cout << "\n";
}

class Solution
{
public:
    Node *reverse(Node *head){
        Node *prev = NULL, *next = NULL, *current = head;
        while (current != NULL){
            next = current->next;
            current->next = prev;
            prev = current;
            current = next;
        }

        return prev;
    }

    Node *addOne(Node *head) {
        Node *new_head = reverse(head);
        Node *current = new_head, *prev = NULL, *current1 = new_head;

        int carry = 0;
        while (current != NULL){
            int sum = 0;
            if (prev == NULL){
                sum = current->data + 1;
            } else {
                sum = current->data + carry;
            }

            carry = sum / 10;
            current->data = sum % 10;
            prev = current;
            current = current->next;
        }

        if (carry == 1){
            Node *new_node = new Node(1);
            prev->next = new_node;
        }

        return reverse(current1);
    }
};

int main() {
    string s;
    cin >> s;

    Node *head = new Node(s[0] - '0');
    Node *tail = head;
    
    for (int i = 1; i < s.size(); i++) {
        tail->next = new Node(s[i] - '0');
        tail = tail->next;
    }

    Solution obj;
    head = obj.addOne(head);
    printList(head);

    return 0;
}

// Input  : 856
// Output : 857

// Time Complexity : O(N)
// Space Complexity : O(1)

// LEETCODE : https://practice.geeksforgeeks.org/problems/add-1-to-a-number-represented-as-linked-list/1