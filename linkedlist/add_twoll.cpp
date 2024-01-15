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

struct node* reverse(struct node* head)
{
    struct node* curr = head;
    struct node* temp = NULL;
    struct node* temp2 = NULL;
    while(curr!=NULL)
    {
        temp2 = curr->next;
        curr->next = temp;
        temp = curr;
        curr = temp2;
    }
    return temp;
}

struct node* add_both(struct node* first, struct node* second)
{
    first=reverse(first);
    second=reverse(second);
    struct node* res=NULL;
    struct node* curr=NULL;
    struct node* temp;
    int sum=0;
    int carry=0;
    while(first!=NULL || second!=NULL)
    {
        sum = carry+(first?first->data:0)+(second?second->data:0);
        carry = (sum>=10)? 1:0;
        sum = sum%10;
        temp = new node(sum);
        if(res==NULL) res=temp;
        else curr->next=temp;
        curr=temp;
        if(first) first=first->next;
        if(second) second=second->next;
    }
    if(carry>0)
    {
        temp = new node(carry);
        curr->next=temp;
        curr=temp;
    }
    res = reverse(res);
    return res;
}


int main()
{
   struct node* first=(struct node*)malloc(sizeof(struct node));
    first=NULL;
    struct node* second=(struct node*)malloc(sizeof(struct node));
    second=NULL;

    int n,m;
    cout<<"Enter n for first linked list: "<<endl;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        first=insert(first);
    }
    cout<<"Enter m for second linked list: "<<endl;
    cin>>m;
    for(int i=0;i<m;i++)
    {
        second=insert(second);
    }
    struct node* res1 = add_both(first,second);
    cout<<"The sum of two linked list is: "<<endl;
    display(res1);
    return 0;
}