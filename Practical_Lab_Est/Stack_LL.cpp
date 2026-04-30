#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};
Node* top = NULL;

void push(int x) {
    Node* newNode = new Node();

    if (newNode == NULL) {
        cout << "Stack Overflow\n";
        return;
    }
    newNode->data = x;
    newNode->next = top;
    top = newNode;
}

void pop() {
    if (top == NULL) {
        cout << "Stack Underflow\n";
        return;
    }

    Node* temp = top;
    cout << "Popped: " << top->data << endl;
    top = top->next;
    delete temp;
}

void peek() {
    if (top == NULL) {
        cout << "Stack is empty\n";
    } else {
        cout << "Top element: " << top->data << endl;
    }
}

void display() {
    Node* temp = top;
    while (temp != NULL) {
        cout << temp->data << " -> ";
        temp = temp->next;
    }
    cout << "NULL\n";
}

int main() {
    push(10);
    push(20);
    push(30);

    display();  
    peek();      

    pop();       
    display();   

    return 0;
}
