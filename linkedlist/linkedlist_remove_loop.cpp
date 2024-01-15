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

void display(struct node* head)
{
    struct node* ptr=head;
    while(ptr!=NULL)
    {
        cout<<ptr->data<<" ";
        ptr=ptr->next;
    }
}

bool check_loop(struct node* head)
{
    struct node* slow = head;
    struct node* fast = head;

    while(slow && fast && fast->next)
    {
        slow = slow->next;
        fast = fast->next->next;
        if(slow==fast) return true;
    }
    return false;
}

struct node* remove_loop(struct node* head)
{
    struct node* slow = head;
    struct node* fast = head;
    while(slow && fast && fast->next)
    {
        slow = slow->next;
        fast = fast->next->next;
        if(slow==fast) break;
    }
    if(slow==head)
    {
        while(fast->next!=slow)
        {
            fast=fast->next;
        }
        fast->next=NULL;
    }
    else if(slow==fast)
    {
        slow=head;
        while(slow->next!=fast->next)
        {
            slow=slow->next;
            fast=fast->next;
        }
        fast->next=NULL;
    }
    return head;
}


int main()
{
    int n;
    cout<<"Enter n: "<<endl;
    cin>>n;
    struct node* head = (struct node*)malloc(sizeof(struct node));
    head=NULL;
    for(int i=0;i<n;i++)
    {
        head=insert(head);
    }
    //display(head);
    head->next->next->next=head->next;
    bool res = check_loop(head);
    if(res) cout<<"loop exists.";
    else cout<<"loop doesnt exist.";
    head=remove_loop(head);
    cout<<"After removing loop: "<<endl;
    display(head);
    return 0;
}