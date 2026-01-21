#include<bits/stdc++.h>
using namespace std;

class node{
public:
    int data;
    node* next;

    node(int val){
        data = val;
        next = NULL;
    }
};

class List{
    node* head;
    node* tail;

public:
    List(){
        head = tail = NULL;
    }

    void insertathead(int val){
        node* newnode =  new node(val);
        if(head == NULL){
            head = tail = newnode;
            return;
        }
        else{
            newnode -> next = head;
            head = newnode;
        }
    }

    void insertatmid(int val, int pos){
        if(pos < 0 ){
            cout<<"Wrong Value";
        }
        else{
            node* temp = head;
            for(int i=0; i<pos-1; i++){
                if(temp == NULL){
                    
                }
            }
        }
    }

    void printing(){
        node* temp = head;
        while(temp != NULL){
            cout<<temp->data<<" ";
            temp = temp->next;
        }
        cout<<"NULL"<<endl;
    }
};

int main(){
    List L1;

    L1.insertathead(10);
    L1.insertathead(20);
    L1.insertathead(70);
    L1.insertathead(45);

    L1.printing();

    return 0;
}
#include<bits/stdc++.h>
using namespace std;

class node{
public:
    int data;
    node* next;

    node(int val){
        data = val;
        next = NULL;
    }
};

class List{
    node* head;
    node* tail;

public:
    List(){
        head = tail = NULL;
    }

    void insertathead(int val){
        node* newnode =  new node(val);
        if(head == NULL){
            head = tail = newnode;
            return;
        }
        else{
            newnode -> next = head;
            head = newnode;
        }
    }

    void insertatmid(int val, int pos){
        if(pos < 0 ){
            cout<<"Wrong Value";
        }
        else{
            node* newnode = new node(val);
            node* temp = head;
            for(int i=0; i<pos-1; i++){
                if(temp == NULL){
                    cout<<"Empty";
                }
                temp = temp->next;
            }
            newnode -> next = temp -> next;
            temp -> next = newnode;
        }
    }
    
     void popathead(){
        if(head == NULL){
            cout<<"Empty\n";
            return;
        }
        else{
            node* temp = head;
            head = head->next;
            temp->next = NULL;
            delete temp;
        }
    }
    
     void popatback(){
        if(head == NULL){
            cout<<"LL is empty\n";
        }
        else{
            node* temp = head;
            while(temp->next != tail){
                temp = temp->next;
        }
            temp->next = NULL;
            delete tail;          
            tail = temp;
        }
    }
    void printing(){
        node* temp = head;
        while(temp != NULL){
            cout<<temp->data<<" -> ";
            temp = temp->next;
        }
        cout<<"NULL"<<endl;
    }
};

int main(){
    List L1;

    L1.insertathead(10);
    L1.insertathead(20);
    L1.insertathead(70);
    L1.insertathead(45);
    L1.insertathead(99);
    L1.insertathead(04);
    
    L1.insertatmid(39,3);
    
    L1.popathead();
    
    L1.popatback();

    L1.printing();

    return 0;
}