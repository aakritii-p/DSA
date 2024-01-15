#include<iostream>
#include<bits/stdc++.h>

using namespace std;

struct node{
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
    if(head==NULL)
    {
        head=temp;
    }
    else
    {
        struct node* ptr = head;
        while(ptr->next!=NULL)
        {
            ptr=ptr->next;
        }
        ptr->next=temp;
    }
    return head;
}

struct node* reverse(struct node* head)
{
    struct node* temp = NULL;
    struct node* temp2 = NULL;
    struct node* curr = head;
    while(curr!=NULL)
    {
        temp2 = curr->next;
        curr->next = temp;
        temp = curr;
        curr = temp2;
    }
    return temp;
}

struct node* add_one(struct node* head)
{
    head=reverse(head);
    struct node* curr = head;
    while(curr!=NULL)
    {
        if(curr->data==9 && curr->next==NULL)
        {
            curr->data=1;
            struct node* temp=(struct node*)malloc(sizeof(struct node));
            temp->data=0;
            temp->next=head;
            head=temp;
            curr=curr->next;
        }
        else if(curr->data==9)
        {
            curr->data=0;
            curr=curr->next;
        }
        else{
            curr->data=curr->data+1;
            curr=curr->next;
            break;
        }
    }
    head=reverse(head);
    return head;
}

void display(struct node* head)
{
    cout<<"Displaying data: "<<endl;
    struct node* ptr=head;
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
    struct node* head = (struct node*)malloc(sizeof(struct node));
    head=NULL;
    for(int i=0;i<n;i++)
    {
        head=insert(head);
    }
    display(head);
    head=add_one(head);
    display(head);
    return 0;
}