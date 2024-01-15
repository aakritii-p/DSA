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
    struct node* headptr = head;
    if(head==NULL) return NULL;
    while(headptr->next!=NULL)
    {
        if(headptr->data==headptr->next->data){
            headptr->next=headptr->next->next;
        }
        else{
            headptr=headptr->next;
        }
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