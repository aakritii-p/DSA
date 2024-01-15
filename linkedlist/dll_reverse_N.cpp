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

struct node* reverse(int k, struct node* head)
{
    if(!head)
      return NULL;
    head->prev = NULL;
    struct node* current = head;
    struct node* prevnode;
    struct node* newhead;
    int count = 0;
    while(count<k && current!=NULL)
    {
        newhead=current;
        prevnode = current->prev;
        current->prev = current->next;
        current->next = prevnode;
        current = current->prev;
        count++;
    }
    if(count>=k)
    {
        head->next = reverse(k,current);
    }
    return newhead;
}

// struct node* reverse(int k, struct node* head)
// {
//     if(!head)
//       return NULL;
//     head->prev = NULL;
//     struct node* current = head;
//     struct node* nextnode;
//     struct node* newhead;
//     int count = 0;
//     while(count<k && current!=NULL)
//     {
//         newhead=current;
//         nextnode = current->next;
//         current->next = current->prev;
//         current->prev = nextnode;
//         current = nextnode;
//         count++;
//     }
//     if(count>=k)
//     {
//         head->next = reverse(k,current);
//     }
//     return newhead;
// }

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
    int k = 3;
    struct node* res_head = reverse(k,head);
    cout<<"After rotating: "<<endl;
    display(res_head);
    return 0;
}