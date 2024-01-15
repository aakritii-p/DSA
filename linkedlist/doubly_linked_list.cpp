#include<iostream>
#include<bits/stdc++.h>

using namespace std;

struct node{
    int data;
    struct node* prev;
    struct node* next;
};

struct node* head, *tail;

void create()
{
    struct node* temp = (struct node*)malloc(sizeof(struct node));
    int x; 
    cout<<"Enter data: "<<endl;
    cin>>x;
    temp->data=x;
    temp->prev=NULL;
    temp->next=NULL;
    if(head==NULL)
    {
        head = tail = temp;
    }
    else
    {
        tail->next = temp;
        temp->prev = tail;
        tail = temp;
    }
}

void insert_at_begin()
{
    struct node* temp = (struct node*)malloc(sizeof(struct node));
    int x; 
    cout<<"Enter data: "<<endl;
    cin>>x;
    temp->data=x;
    temp->prev=NULL;
    temp->next=head;
    head->prev=temp;
    head=temp;
}

void insert_at_end()
{
    struct node* temp = (struct node*)malloc(sizeof(struct node));
    int x; 
    cout<<"Enter data: "<<endl;
    cin>>x;
    temp->data=x;
    temp->prev=tail;
    temp->next=NULL;
    tail->next=temp;
    tail=temp;
}

void insert_at_pos()
{
    struct node* temp = (struct node*)malloc(sizeof(struct node));
    struct node* ptr = head;
    int pos;
    cout<<"Enter pos: "<<endl;
    cin>>pos;
    int x; 
    int i=1;
    cout<<"Enter data: "<<endl;
    cin>>x;
    temp->data=x;
    while(i<pos-1)
    {
        ptr = ptr -> next;
        i++;
    }
    temp->prev=ptr;
    temp->next=ptr->next;
    ptr->next=temp;
    temp->next->prev=temp;


}

void del_from_begin()
{
    struct node* temp;
    if(head==NULL)
    {
        cout<<"empty list";
    }
    else
    {
        temp = head;
        head=head->next;
        head->prev=NULL;
        free(temp);
    }
}

void del_at_end()
{
    struct node* temp = tail;
    tail->prev->next=NULL;
    tail=tail->prev;
    free(temp);
}

void del_at_pos()
{
    int pos;
    cout<<"Enter position: "<<endl;
    cin>>pos;
    int i =1 ;
    struct node* ptr=head;
    while(i<pos)
    {
        ptr=ptr->next;
        i++;
    }
    ptr->prev->next=ptr->next;
    ptr->next->prev=ptr->prev;
    free(ptr);
}

void reverse()
{
    // struct node* current = head;
    // struct node* nextnode, *previous;
    // while(current!=NULL)
    // {
    //     nextnode = current -> next;
    //     current -> next = current -> prev;
    //     current -> prev = nextnode;
    //     previous = current;
    //     current = nextnode;
    // }
    // return previous;

    struct node* current = head;
    struct node* prevnode;
    while(current!=NULL)
    {
        prevnode = current -> prev;
        current -> prev = current -> next;
        current -> next = prevnode;
        current = current->prev;
    }
    current = tail;
    tail = head;
    head = current;
}

void display()
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
    int n;
    cout<<"Enter n: "<<endl;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        create();
    }
    display();
    insert_at_begin();
    insert_at_end();
    insert_at_pos();
    display();
    cout<<"After deletion: "<<endl;
    del_from_begin();
    del_at_end();
    del_at_pos();
    display();
    cout<<"reversing"<<endl;
    reverse();
    display();
    return 0;
}