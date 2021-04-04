#include<bits/stdc++.h>
using namespace std;

struct Node{
    int val;
    Node *next;
};

Node *newNode(int value){
    Node *n=new Node;
    n->next=NULL;
    n->val=value;
    return(n);
}

class linkedList{

Node *head,*tail,*temp;
int size=0;
public:
    void createList(){
        head=NULL;
        tail=head;
        temp=head;
        size=0;
    }

public:
    void insert(int value){
        if(head==NULL){
            head=newNode(value);
            tail=head;
        }
        else{
        temp=tail;
        tail=newNode(value);
        temp->next=tail;
        }
        size++;
    }
    
public:
    void printList(){
        temp=head;
        while(temp!=NULL){
            cout<<temp->val<<",";
            temp=temp->next;
        }
    }
};

int main(){

    linkedList l;
    l.createList();

    for(int i=1;i<6;i++)
        l.insert(i);

    l.printList();


    return(0);
}