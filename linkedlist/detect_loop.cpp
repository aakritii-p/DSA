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
    cout<<"Enter data: "<<endl;
    cin>>data;
    temp->data=data;
    temp->next=NULL;
    if(head==NULL)
    {
        head=temp;
        return;
    }
    else{
        struct node* ptr=head;
        while(ptr->next!=NULL)
        {
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

bool detectLoop(){
    struct node* slow= head;
    struct node* fast= head;
    while(slow && fast && fast->next){
        slow=slow->next;
        fast=fast->next->next;
        if(slow==fast){
            return true;
        }
    }
    return false;
}



int main()
{
    int n;
    cout<<"Enter the number of nodes you want to create:"<<endl;
    cin>>n;
    for(int i=0;i<n;i++){
        insert();
    }
    head->next->next=head->next; //creating loop
    bool isLoop = detectLoop();
    if(isLoop){
        cout<<"Loop exists"<<endl;
    }
    else{
        cout<<"Loop doesnt exist."<<endl;
    }
    return 0;
}