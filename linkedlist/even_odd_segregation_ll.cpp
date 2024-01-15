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

struct node* even_odd(struct node* head)
{
    struct node* even=NULL;
    struct node*  e;
    struct node*  odd=NULL;
    struct node*  o;
    struct node* curr = head;
        
    if(!head) return NULL;
    while(curr!=NULL)
    {
        if((curr->data)%2==0)
        {
            if(even==NULL)
            {
                even=e=curr;
            }
            else
            {
                e->next=curr;
                e=e->next;
            }
        }
        else
        {
            if(odd==NULL)
            {
                odd=o=curr;
            }
            else
            {
                o->next=curr;
                o=o->next;
            }
            
        }
        curr=curr->next;
    }
    
    if(even==NULL||odd==NULL) return head;
    
    if(e) e->next=odd;
    if(o) o->next=NULL;
    
    if(even) return even;
    else return odd;
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
    head=even_odd(head);
    display(head);
    return 0;
}