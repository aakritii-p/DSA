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

struct node* remove_duplicates(struct node* head)
{
    map<int,int> m;
    struct node* curr = head;
    struct node* prev = curr;
    m[curr->data]=1;
    curr=curr->next;
    while(curr!=NULL)
    {
        if(m[curr->data]){
            prev->next=curr->next;
            free(curr);
        }
        else {
            m[curr->data]=1;
            prev=curr;
        }
        curr=prev->next;
    }
    return head;
}


void display(struct node* head)
{
    cout<<"Displaying data.."<<endl;
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
    display(head);    
    head = remove_duplicates(head);
    display(head);    
    return 0;
}