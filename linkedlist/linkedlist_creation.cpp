#include<iostream>
#include<bits/stdc++.h>

using namespace std;

struct node
{
    int data;
    struct node* next;
};

struct node* insert(struct node* head)
{
    struct node* temp=(struct node*)malloc(sizeof(struct node));
    int data;
    cout<<"Enter data: "<<endl;
    cin>>data;
    temp->data=data;
    temp->next=NULL;
    struct node* ptr;

    if(head==NULL)
    {
        head=ptr=temp;
    }
    else
    {
        ptr->next=temp;
        ptr=temp;
    }
    return head;
}

struct node* insert_beg(struct node* head)
{
    struct node* temp=(struct node*)malloc(sizeof(struct node));
    int data;
    cout<<"Enter data: "<<endl;
    cin>>data;
    temp->data=data;
    temp->next=head;
    head=temp;
    return head;
}

struct node* insert_at_pos(struct node* head)
{
    int pos;
    cout<<"Enter the position to be inserted at: "<<endl;
    cin>>pos;
    int data;
    cout<<"Enter data to be inserted: "<<endl;
    cin>>data;
    struct node* temp=(struct node*)malloc(sizeof(struct node));
    temp->data=data;
    temp->next=NULL;
    int k = 1;
    struct node* ptr = head;
    while(k<pos-1)
    {
        ptr=ptr->next;
        k++;
    }
    
    temp->next=ptr->next;
    ptr->next=temp;
    return head;

}

struct node* insert_end(struct node* head)
{
    struct node* temp=(struct node*)malloc(sizeof(struct node));
    int data;
    cout<<"Enter data: "<<endl;
    cin>>data;
    temp->data=data;
    temp->next=NULL;
    struct node* ptr=head;
    while(ptr->next!=NULL)
    {
        ptr=ptr->next;
    }
    ptr->next=temp;
    return head;
}

struct node* delete_beg(struct node* head)
{
    struct node* ptr = head;
    head = head->next;
    free(ptr);
    return head;
}

struct node* delete_end(struct node* head)
{
    struct node* ptr = head;
    struct node* prev;
    while(ptr->next!=NULL)
    {
        prev=ptr;
        ptr=ptr->next;
    }
    free(ptr);
    prev->next=NULL;
    return head;
}

struct node* delete_pos(struct node* head)
{
    int pos;
    cout<<"Enter the position to be deleted at: "<<endl;
    cin>>pos;
    int k = 1;
    struct node* ptr = head;
    while(k<pos-1)
    {
        ptr=ptr->next;
        k++;
    }
    ptr->next=ptr->next->next;
    free(ptr->next);
    return head;
}

void display(struct node* head)
{
    struct node* ptr = head;
    while(ptr!=NULL)
    {
        cout<<ptr->data<<" ";
        ptr=ptr->next;
    }
}


int main()
{
    struct node* head = (struct node*)malloc(sizeof(struct node));
    head=NULL;
    int n;
    cout<<"Enter the number of nodes you want to insert: "<<endl;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        head=insert(head);
    }
    display(head);
    cout<<"Insertion at beginning: "<<endl;
    head=insert_beg(head);
    display(head);
    cout<<"Insertion at end: "<<endl;
    head=insert_end(head);
    display(head);
    cout<<"Insertion at position p: "<<endl;
    head=insert_at_pos(head);
    display(head);
    cout<<"Deletion from beginning: "<<endl;
    head=delete_beg(head);
    display(head);
    cout<<"Deletion from end: "<<endl;
    head=delete_end(head);
    display(head);
    cout<<"Deletion at position p: "<<endl;
    head=delete_pos(head);
    display(head);
    return 0;
}