#include <bits/stdc++.h>
using namespace std;

class node {
public:
    int data;
    node* prev;
    node* next;

    node(int val) {
        data = val;
        prev = NULL;
        next = NULL;
    }
};

class List {
    node* head;
    node* tail;

public:
    List() {
        head = tail = NULL;
    }

    void insertathead(int val) {
        node* newnode = new node(val);

        if (head == NULL) {
            head = tail = newnode;
        } else {
            newnode->next = head;
            head->prev = newnode;
            head = newnode;
        }
    }

    void insertatmid(int val, int pos) {
        if (pos < 0) {
            cout << "Wrong Value\n";
            return;
        }

        if (pos == 0) {
            insertathead(val);
            return;
        }

        node* temp = head;
        for (int i = 0; i < pos - 1; i++) {
            if (temp == NULL) {
                cout << "Invalid\n";
                return;
            }
            temp = temp->next;
        }

        if (temp == tail) {
            node* newnode = new node(val);
            tail->next = newnode;
            newnode->prev = tail;
            tail = newnode;
            return;
        }

        node* newnode = new node(val);
        newnode->next = temp->next;
        newnode->prev = temp;
        temp->next->prev = newnode;
        temp->next = newnode;
    }

    void popathead() {
        if (head == NULL) {
            cout << "Empty\n";
            return;
        }

        node* temp = head;
        head = head->next;

        if (head != NULL)
            head->prev = NULL;
        else
            tail = NULL;

        delete temp;
    }

    void popatback() {
        if (tail == NULL) {
            cout << "LL is empty\n";
            return;
        }

        node* temp = tail;
        tail = tail->prev;

        if (tail != NULL)
            tail->next = NULL;
        else
            head = NULL;

        delete temp;
    }

    void printing() {
        node* temp = head;
        while (temp != NULL) {
            cout << temp->data << " <-> ";
            temp = temp->next;
        }
        cout << "NULL\n";
    }
};

int main() {
    List L1;

    L1.insertathead(10);
    L1.insertathead(20);
    L1.insertathead(70);
    L1.insertathead(45);
    L1.insertathead(99);
    L1.insertathead(4);

    L1.insertatmid(39, 3);

    L1.popathead();
    L1.popatback();

    L1.printing();
    return 0;
}
