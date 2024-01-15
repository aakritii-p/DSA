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

void display(struct node* head)
{
    struct node* ptr = head;
    while(ptr!=NULL)
    {
        cout<<ptr->data<<" ";
        ptr=ptr->next;
    }
}

struct node* reverse(struct node* head)
{
    struct node* temp=NULL;
    struct node* temp2;
    struct node* ptr = head;
    while(ptr!=NULL)
    {
        temp2=ptr->next;
        ptr->next=temp;
        temp=ptr;
        ptr=temp2;
    }
    return temp;
}

struct node* delete_right(struct node* head)
{
    head=reverse(head);
    struct node* curr = head;
    int mx = head->data;
    struct node* prev = head;
    head=head->next;
    while(head!=NULL)
    {
        if(head->data>=mx)
        {
            mx=head->data;
            prev=head;
            head=head->next;
        }
        else
        {
            prev->next=head->next;
            head=prev->next;
        }
    }
    head=reverse(curr);
    return head;
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
    head=delete_right(head);
    display(head);
    return 0;
}