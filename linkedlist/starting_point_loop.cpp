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

int starting_point_of_loop(struct node* head)
{
    struct node* slow=head;
    struct node* fast=head;
    while(slow && fast && fast->next)
    {
        slow=slow->next;
        fast=fast->next->next;
        if(slow==fast)
        {
            break;
        }
    }
    slow=head;
    while(slow!=fast)
    {
        slow=slow->next;
        fast=fast->next;
    }
    return fast->data;
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
    int n;
    cout<<"Enter n: "<<endl;
    cin>>n;
    struct node* head=(struct node*)malloc(sizeof(struct node));
    head=NULL;
    for(int i=0;i<n;i++)
    {
        head=insert(head);
    }
    head->next->next->next=head->next->next;
    int res;
    res = starting_point_of_loop(head);
    cout<<"starting point of loop is:"<<res<<endl; 
    return 0;
}