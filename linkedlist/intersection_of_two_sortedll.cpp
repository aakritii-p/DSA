#include<iostream>
#include<bits/stdc++.h>
using namespace std;
struct node{
    int data;
    struct node* next;
    node ( int x)
    {
        data = x;
        next = NULL;
    }
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

void display(struct node* head)
{
    struct node* ptr = head;
    while(ptr!=NULL)
    {
        cout<<ptr->data<<" ";
        ptr=ptr->next;
    }
}

struct node* intersection(struct node* head1, struct node* head2)
{
    struct node* ptr1=head1;
    struct node* ptr2=head2;
    struct node* head=NULL;
    struct node* curr=NULL;
    while(ptr1 && ptr2)
    {
        if(ptr1->data == ptr2->data)
        {
            struct node* temp = new node(ptr1->data);
            if(head==NULL)
            {
                head=temp;
                curr=temp;
            }
            else{
                curr->next=temp;
                curr=curr->next;
            }
            ptr1=ptr1->next;
            ptr2=ptr2->next;
        }
        else if(ptr1->data<ptr2->data)
        {
            ptr1=ptr1->next;
        }
        else
        {
            ptr2=ptr2->next;
        }
    }
    return head;
}


int main()
{
    struct node* head1=(struct node*)malloc(sizeof(struct node));
    head1=NULL;
    struct node* head2=(struct node*)malloc(sizeof(struct node));
    head2=NULL;

    int n,m;
    cout<<"Enter n for first linked list: "<<endl;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        head1=insert(head1);
    }
    cout<<"Enter m for second linked list: "<<endl;
    cin>>m;
    for(int i=0;i<m;i++)
    {
        head2=insert(head2);
    }
    struct node* res = intersection(head1,head2);
    cout<<"Displaying data of intersected linked list: "<<endl;
    display(res);
    return 0;
}