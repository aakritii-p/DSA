#include<iostream>
#include<bits/stdc++.h>
using namespace std;

struct node{
    int data;
    struct node* next;
};

struct node* insert(struct node* head){
    struct node* temp = (struct node*)malloc(sizeof(struct node));
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

struct node* reverse(struct node* head,int k)
{
    struct node* temp =(struct node*)malloc(sizeof(struct node));
    struct node* temp2 = (struct node*)malloc(sizeof(struct node));
    temp = NULL;
    temp2 = NULL;
    int count = 0;
    struct node* ptr = head;
    while(ptr!=NULL && count<k){
        temp2=ptr->next;
        ptr->next=temp;
        temp=ptr;
        ptr=temp2;
        count++;
    }
    if(ptr!=NULL)
    {
        head->next=reverse(ptr,k);
    }
    return temp;
}

void display(struct node* head)
{
    struct node* ptr = head;
    cout<<"Displaying data: "<<endl;
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
    cout<<"Enter n: "<<endl;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        head=insert(head);
    }
    display(head);
    int k;
    cout<<"Enter value of k: "<<endl;
    cin>>k;
    head=reverse(head,k);
    display(head);
}