#include<iostream>
#include<bits/stdc++.h>

using namespace std;

struct node{
    int data;
    struct node* next;
};
struct node* tail; //maintaining a single pointer- tail

void insert()
{
    struct node* temp = (struct node*)malloc(sizeof(struct node));
    int x;
    cout<<"Enter data: "<<endl;
    cin>>x;
    temp->data=x;
    temp->next=NULL;
    if(tail==NULL)
    {
        tail=temp;
        tail->next=temp;
    }
    else{
        temp->next=tail->next;
        tail->next=temp;
        tail = temp;
    }

    //if there was head pointer
    // if(head==NULL)
    // {
    //     head=tail=temp;
    //     tail->next=temp;
    // }
    // else
    // {
    //     temp->next=head;
    //     tail->next=temp;
    //     tail=temp;
    // }
}

void insert_at_begin()
{
    struct node* temp = (struct node*)malloc(sizeof(struct node));
    int x;
    cout<<"Enter data to be inserted at the beginning: "<<endl;
    cin>>x;
    temp->data=x;
    temp->next=NULL; 
    if(tail==NULL)
    {
        tail=temp;
        tail->next=temp;
    }
    else
    {
        temp->next=tail->next;
        tail->next=temp;
    }
}

void insert_at_end()
{
    struct node* temp = (struct node*)malloc(sizeof(struct node));
    int x;
    cout<<"Enter data to be inserted at the end: "<<endl;
    cin>>x;
    temp->data=x;
    temp->next=NULL; 
    if(tail==NULL)
    {
        tail=temp;
        tail->next=temp;
    }
    else
    {
        temp->next=tail->next;
        tail->next=temp;
        tail=temp;
    }
}

int count()
{
    int cnt=0;
    struct node* ptr = tail->next;
    while(ptr->next!=tail->next)
    {
        cnt++;
        ptr=ptr->next;
    }
    cnt++;
    return cnt;
}

void insert_anywhere()
{
    int pos;
    cout<<"Enter the position where you want to insert:"<<endl;
    cin>>pos;
    struct node* ptr;
    int length = count();
    if(pos<0||pos>length)
    {
        cout<<"invalid position!"<<endl;
    }
    else if(pos==1)
    {
        insert_at_begin();
    }
    else
    {
        struct node* temp = (struct node*)malloc(sizeof(struct node));
        int x;
        cout<<"Enter data to be inserted at the pos: "<<endl;
        cin>>x;
        temp->data=x;
        temp->next=NULL; 
        ptr=tail->next;
        int i=1;
        while(i<pos-1)
        {
            ptr=ptr->next;
            i++;
        }
        temp->next=ptr->next;
        ptr->next=temp;
    }
    
}

void del_from_begin()
{
    struct node* ptr;
    ptr=tail->next;
    if(tail==NULL)
    {
        cout<<"list is empty."<<endl;
        return;
    }
    else if(tail->next==tail)
    {
        tail=NULL;
        free(ptr);
    }
    else
    {
        tail->next=ptr->next;
        free(ptr);
    }
}

void del_from_end()
{
    struct node* current, *previous;
    current = tail->next;
    while(current->next!=tail->next)
    {
        previous=current;
        current=current->next;
    }
    previous->next=tail->next;
    tail=previous;
    free(current);

}

void del_at_pos()
{
    struct node* current, * nextnode;
    int i=1,pos,l;
    current=tail->next;
    cout<<"Enter position: "<<endl;
    cin>>pos;
    l=count();
    if(pos<1||pos>l)
    {
        cout<<"invalid pos."<<endl;
    }
    else if(pos==1)
    {
        del_from_begin();
    }
    else
    {
        while(i<(pos-1))
        {
            current=current->next;
            i++;
        }
        nextnode=current->next;
        current->next=nextnode->next;
        free(nextnode);
    }

}

void reverse()
{
    struct node* prev,*current,*nextnode;
    current = tail->next;
    nextnode = current->next;
    if(tail==NULL) cout<<"list is empty.";
    while(current!=tail)
    {
        prev=current;
        current = nextnode;
        nextnode = current->next;
        current->next = prev;

    }
    nextnode->next = tail;
    tail = nextnode;
}

void display()
{
    struct node* ptr = tail->next;
    while(ptr->next!=tail->next)
    {
        cout<<ptr->data<<" ";
        ptr=ptr->next;
    }
    cout<<ptr->data<<" ";
}


int main()
{
    int n;
    cout<<"Enter the number of nodes you want to insert: "<<endl;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        insert();
    }
    display();
    insert_at_begin();
    insert_at_end();
    insert_anywhere();
    display();
    del_from_begin();
    del_from_end();
    del_at_pos();
    cout<<"After deletion: "<<endl;
    display();
    cout<<"Reverse: "<<endl;
    reverse();
    display();

    return 0;
}