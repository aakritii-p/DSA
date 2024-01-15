#include<iostream>
#include<bits/stdc++.h>

using namespace std;

struct node{
    int data;
    struct node* next;
};
node* head;

void insert(){
    struct node* temp=(struct node*)malloc(sizeof(struct node));
    int data;
    cout<<"Enter data to be inserted:"<<endl;
    cin>>data;
    temp->data=data;
    temp->next=NULL;
    if(head==NULL){
        head=temp;
        return;
    }
    else{
        struct node* ptr=head;
        while(ptr->next!=NULL){
            ptr=ptr->next;
        }
        ptr->next=temp;
    }

}

void display(){
    struct node* ptr=head;
    while(ptr!=NULL){
        cout<<ptr->data<<" ";
        ptr=ptr->next;
    }
    
}

bool isPalindrome()
{
    struct node* slow = head;
    struct node* fast = head;
    while(fast && fast->next)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    
    struct node* prev = NULL;
    struct node* next;
    struct node* curr = slow;
    
    while(curr!=NULL)
    {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    fast = head;
    while(prev!=NULL)
    {
        if(prev->data!=fast->data)
            return false;
        prev=prev->next;
        fast=fast->next;
    }
    return true;
}


int main(){
    int n;
    cout<<"Enter the number of nodes you want to insert:"<<endl;
    cin>>n;
    for(int i=0;i<n;i++){
        insert();
    }
    display();
    bool res = isPalindrome();
    if(res)
    {
        cout<<"Yes it is palindrome."<<endl;
    }
    else
    {
        cout<<"No it is not a palindrome."<<endl;
    }
    return 0;
}