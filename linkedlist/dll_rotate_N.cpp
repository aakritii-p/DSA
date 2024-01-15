#include<iostream>
#include<bits/stdc++.h>

using namespace std;

struct node
{
    int data;
    struct node* prev;
    struct node* next;
};

struct node* insert(struct node* head)
{
    struct node* temp = (struct node*)malloc(sizeof(struct node));
    int x;
    cout<<"Enter data: "<<endl;
    cin>>x;
    temp->data=x;
    temp->prev=NULL;
    temp->next=NULL;
    struct node* ptr;
    if(head==NULL)
    {
        head=ptr=temp;
    }
    else
    {
        ptr->next=temp;
        temp->prev=ptr;
        ptr=temp;
    }
    return head;
}

struct node* rotate(int n, struct node* head)
{
    struct node* current = head;
    int count = 1;

    while(current!=NULL && count<n)
    {
        current = current -> next;
        count++;   
    }

    struct node* nth_node = current;

    while(current->next!=NULL)
    {
        current = current->next;
    }

     current->next=head;
     head->prev=current;
     head=nth_node->next;
     head->prev=NULL;
     nth_node->next=NULL;
     return head;

}

void display(struct node* head)
{
    struct node* current=head;
    while(current!=NULL)
    {
        cout<<current->data<<" ";
        current=current->next;
    }
}

int main()
{
    int n;
    struct node* head=NULL;
    cout<<"Enter n: "<<endl;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        head=insert(head);
    }
    display(head);
    int k = 2;
    struct node* res_head = rotate(k,head);
    cout<<"After rotating: "<<endl;
    display(res_head);
    return 0;
}