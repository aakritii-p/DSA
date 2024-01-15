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

void reverse(){
    // struct node* temp = (struct node*)malloc(sizeof(struct node));
    // struct node* temp2 = (struct node*)malloc(sizeof(struct node));
    struct node* temp;
    struct node* temp2;
    temp=NULL, temp2=NULL;
    while(head!=NULL){
        temp2=head->next;
        head->next=temp;
        temp=head;
        head=temp2;
    }
    head=temp;
}

// prev,curr,next
// while(curr!=NULL)
// {
//     next=curr->next;
//     curr->next=prev;
//     prev=curr;
//     curr=next;
// }
// curr=prev;

void display(){
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
    display();
    cout<<"Reversing the linked list now: "<<endl;
    reverse();
    display();
    return 0;
}