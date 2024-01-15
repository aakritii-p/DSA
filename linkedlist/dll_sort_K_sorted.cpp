#include<iostream>
#include<bits/stdc++.h>

using namespace std;

struct node
{
    int data;
    struct node* prev;
    struct node* next;
};
struct node* head;

void insert()
{
    struct node* temp=(struct node*)malloc(sizeof(struct node));
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
}

struct compare{
    bool operator() (struct node* first, struct node* second)
    {
        return first->data > second->data;
    }
};

void sortKsorted(int k)
{
    if(head==NULL)
        return;
    priority_queue<node*, vector<node*>, compare> pq;

    struct node* newhead = NULL, *curr;

    for(int i=0; head!=NULL && i<=k; i++)
    {
        pq.push(head);
        head=head->next;
    }

    while(!pq.empty())
    {
        if(newhead==NULL)
        {
            newhead = pq.top();
            newhead->prev = NULL;
            curr=newhead;
        }
        else
        {
            curr->next = pq.top();
            pq.top()->prev = curr;
            curr = pq.top();
        }
    

    pq.pop();

    if(head!=NULL)
    {
        pq.push(head);
        head=head->next;
    }
    }
    curr->next = NULL;
    head=newhead;
}


void display()
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
  for( int i=0;i<n;i++)
  {
    insert();
    // 3 6 2 12 56 8
  }
  display();
  sortKsorted(2);
  cout<<"After sorting: "<<endl;
  display();
  return 0;
}