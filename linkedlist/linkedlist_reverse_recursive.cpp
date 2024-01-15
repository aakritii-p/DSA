#include<iostream>
#include<bits/stdc++.h>

using namespace std;

struct node{
    int data;
    struct node* next;
};
node* head;


void insert(){
    struct node* temp=(struct node*)malloc(sizeof(struct node));
    int data;
    cout<<"Enter data:"<<" ";
    cin>>data;
    temp->data=data;
    temp->next=NULL;
    if(head==NULL){
        head=temp;
        return;
    }
    else{
        struct node* ptr= head;
        while(ptr->next!=NULL){
            ptr=ptr->next;
        }
        ptr->next=temp;
    }
}

struct node* reverseList(struct node* head){
     if(head==NULL||head->next==NULL)
            return head; 
    struct node* rest = reverseList(head->next);
    head->next->next=head;
    head->next=NULL;
    
    return rest;
}


void display(struct node* head){
    struct node* ptr= head;
    while(ptr!=NULL){
        cout<<ptr->data<<" ";
        ptr=ptr->next;
    }
}

int main(){
    int n;
    cout<<"Enter number of nodes to be created:"<<endl;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        insert();
    }
    display(head);
    cout<<endl;
    cout<<"Reversing the linked list now: "<<endl;
    head=reverseList(head);
    display(head);
    return 0;
}